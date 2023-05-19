#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>
#include <ArduinoOTA.h>
#include "variables.h"
#include "secret.h"
#include "process_LCD_packets.h"
#include "process_LCD_packets_SERVICE.h"
#include "process_LCD_packets_LONG.h"

const char* ssid = _SSID;         // SSID and PASSWORD are stored in secret.h
const char* password = _PASSWORD;
const char* hostname = "RS485Module";

SoftwareSerial RS485Serial(D4, D3); // RX, TX
ESP8266WebServer server(80); // Create a web server on port 80

#include "index_html.h"
#include "handle_index_html.h"
#include "handle_form.h"

void setup() {
  Serial.begin(115200);
  RS485Serial.begin(19200); // Set the baud rate for the RS485 module

  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Initialize ArduinoOTA
  ArduinoOTA.setHostname(hostname);
  ArduinoOTA.begin();

  Serial.println();
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("OTA Hostname: ");
  Serial.println(hostname);
  Serial.println("ArduinoOTA started");
  Serial.println();

  // Setup web server
  server.on("/", handle_index_html);
  server.on("/ajax", handleAjaxRequest);
  server.on("/form", HTTP_GET, handleForm);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  // Handle OTA update functionality
  ArduinoOTA.handle();
  // Handle web server requests
  server.handleClient();
  // Read RS485Serial Data
  if (RS485Serial.available()) {  
      byte response = RS485Serial.read();
      buffer[bufferIndex++] = response;
      // if (prevByte == the_packet_end[0] && response == the_packet_end[1]) {
      //   send_btn_command();
      // }
      if (prevByte == the_packet_start[0] && response == the_packet_start[1]) {
        bufferIndex = 0;
      }
      if (prevByte == the_packet_end[0] && response == the_packet_end[1]) {
        the_packet_Buffer();
        bufferIndex = 0;
      }
      prevByte = response;
  }  
}

void the_packet_Buffer() {
  //Build the_packet
  // the_packet = "";
  // for (int i = 0; i < bufferIndex; i++) {
  //   String hexString = String(buffer[i], HEX);
  //   the_packet += "0x" + hexString + " ";
  // }
  // the_packet.trim();
///////////   Break Down the_packet into Categories    ////////////////////////////////////
/*********************************************************************************************\
 ***** KEEP ALIVE
\*********************************************************************************************/

if (buffer[0] == 0x1 && buffer[1] == 0x1) { //10 02 01 01 00 14 10 03 its a keep-alive packet not useful
      //Serial.print("----------------------  keep-alive  ----------------------");
      //Serial.println(keep_alive_count);     
      // Serial.println(the_packet);
      // Serial.println();
      keep_alive_count++;   
      if (keep_alive_count == 1 && btn_send_yes == 1){
        send_btn_command();
        keep_alive_count = 0;
      }  
/*********************************************************************************************\
 ***** LED STATUS
\*********************************************************************************************/
} else if (buffer[0] == 0x1 && buffer[1] == 0x2) { //if packet starts with a 10 02 01 02 its an LED Status
      keep_alive_count = 0;
      //Serial.println("----------------------  LED Status  ----------------------");
      byte bitArray[2][8];
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
          byte currentBit = bitRead(buffer[2 + i], j);
          bitArray[i][j] = currentBit; // write bit to bit array
        }
      }
      led_heater1 = bitArray[0][0]; // Heater1 ON/OFF
      led_valve3 = bitArray[0][1]; // Valve3 ON/OFF
      led_check_system = bitArray[0][2]; // Check System ON/OFF
      led_pool = bitArray[0][3]; // Pool ON/OFF
      led_spa = bitArray[0][4]; // Spa ON/OFF
      if (buffer[6] == 0x20) { // Filter 0=OFF 1=ON 2=Blinking
      //if (bitRead(buffer[6], 1) == 1){  // Filter 0=OFF 1=ON 2=Blinking
        led_filter = bitArray[0][5] ? 2 : 0;
      } else {
        led_filter = bitArray[0][5];
      }
      led_lights = bitArray[0][6]; // Lights UNDERWATER ON/OFF
      led_aux1 = bitArray[0][7]; // Aux1 ON/OFF
      led_aux2 = bitArray[1][0]; // Aux2 ON/OFF

      if (bitRead(buffer[7], 1) == 1){ // Service 0=OFF 1=ON 2=Blinking
        led_service = bitArray[1][1] ? 2 : 0;
      } else {
        led_service = bitArray[1][1];
      }
      led_aux3 = bitArray[1][2]; // Aux3 ON/OFF
      led_aux4 = bitArray[1][3]; // Aux4 ON/OFF
      led_aux5 = bitArray[1][4]; // Aux5 ON/OFF
      led_aux6 = bitArray[1][5]; // Aux6 ON/OFF
      led_valve4 = bitArray[1][6]; // Valve4 ON/OFF
      led_spillover = bitArray[1][7]; // Spillover ON/OFF
/*********************************************************************************************\
 ***** LCD Packet
\*********************************************************************************************/
} else if (buffer[0] == 0x1 && buffer[1] == 0x3) { //if packet starts with a 10 02 01 03 its an LCD Packet  the_packet.startsWith("0x1 0x3 ")
      keep_alive_count = 0;
      //Serial.println("----------------------  LCD Packet  ----------------------");
      //Serial.println(the_packet);
      // String text = "";
      // for (int i = 0; i < sizeof(buffer); i++) {
      //   text += (char)buffer[i];
      // }
      // text.trim();
      // for (int i = 0; i < text.length(); i++) {
      //   Serial.print(text[i]);
      // }
      //  Serial.println();
   
process_LCD_packets(buffer, sizeof(buffer) / sizeof(buffer[0]), line1, line2);
  // Serial.print("Line1: ");
  // Serial.println(line1);
  // Serial.print("Line2: ");
  // Serial.println(line2);
  // Serial.print("heater1_status: ");
  // Serial.println(lcd_heater_status);
  // Serial.print("salt_level: ");
  // Serial.println(lcd_salt_level);
  // Serial.print("filter_speed: ");
  // Serial.println(lcd_filter_speed);
  // Serial.print("Pool Temp: ");
  // Serial.println(lcd_pool_temp); 
  //   Serial.print("Air Temp: ");
  // Serial.println(lcd_air_temp);
  //   Serial.print("Pool Chlorinator: ");
  // Serial.println(lcd_chlorinator_value);
  //     Serial.print("day_of_week: ");
  // Serial.println(lcd_day_of_week);
  //         Serial.print("hour: ");
  // Serial.println(hour);
  //         Serial.print("minute: ");
  // Serial.println(minute);
  //       Serial.print("ampm: ");
  // Serial.println(ampm);
//         Serial.print("time: ");
//   Serial.println(lcd_aqua_time);
//          Serial.print("LCD Aux1: ");
//   Serial.println(lcd_aux1_btn); 
//            Serial.print("LCD Aux2: ");
//   Serial.println(lcd_aux2_btn); 
//            Serial.print("LCD Aux3: ");
//   Serial.println(lcd_aux3_btn); 
//            Serial.print("LCD Aux4: ");
//   Serial.println(lcd_aux4_btn); 
//            Serial.print("LCD Aux5: ");
//   Serial.println(lcd_aux5_btn); 
//            Serial.print("LCD Aux6: ");
//   Serial.println(lcd_aux6_btn); 
// Serial.println();
// Serial.println();

/*********************************************************************************************\
 ***** LCD Packet SERVICE
\*********************************************************************************************/
} else if (buffer[0] == 0x2 && buffer[1] == 0x3) { //if packet starts with a 10 02 01 03 its an LCD Packet  the_packet.startsWith("0x1 0x3 ")
      keep_alive_count = 0;
      //Serial.println("----------------------  LCD Packet SERVICE  ----------------------");
      // Serial.println(the_packet);
      // String text = "";
      // for (int i = 0; i < sizeof(buffer); i++) {
      //   text += (char)buffer[i];
      // }
      // text.trim();
      // for (int i = 0; i < text.length(); i++) {
      //   Serial.print(text[i]);
      // }
      //  Serial.println();
      process_LCD_packets_SERVICE(buffer, sizeof(buffer) / sizeof(buffer[0]), line1, line2);
/*********************************************************************************************\
 ***** LCD Packet LONG
\*********************************************************************************************/
} else if (buffer[0] == 0x3 && buffer[1] == 0x3) { //if packet starts with a 10 02 01 03 its an LCD Packet  the_packet.startsWith("0x1 0x3 ")
      keep_alive_count = 0;
      //Serial.println("----------------------  LCD Packet LONG  ----------------------");
      // Serial.println(the_packet);
      // String text = "";
      // for (int i = 0; i < sizeof(buffer); i++) {
      //   text += (char)buffer[i];
      // }
      // text.trim();
      // for (int i = 0; i < text.length(); i++) {
      //   Serial.print(text[i]);
      // }
      //  Serial.println();
      process_LCD_packets_LONG(buffer, sizeof(buffer) / sizeof(buffer[0]), line1, line2);
/*********************************************************************************************\
 ***** OTHER
\*********************************************************************************************/
} else {
      keep_alive_count = 0;
      // Serial.println("----------------------  OTHER  ----------------------");
      // Serial.println(the_packet);
      // String text = "";
      // for (int i = 0; i < sizeof(buffer); i++) {
      //   text += (char)buffer[i];

      // }
      // text.trim();
      // for (int i = 0; i < text.length(); i++) {
      //   Serial.print(text[i]);
      // }
      //  Serial.println();
}
}

