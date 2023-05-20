/*********************************************************************************************\
 ************** Global variables
\*********************************************************************************************/
String data = "";
byte prevByte = 0x00;
byte buffer[256];
int bufferIndex = 0;
String the_packet = "";
byte the_packet_start[] = {0x10, 0x02};
byte the_packet_end[] = {0x10, 0x03};
//String btn_command_to_send = "";
//uint8_t btn_command_to_send[16];
////uint8_t btn_command_to_send[];
int btn_send_yes = 0;
int keep_alive_count = 0;
String LCD_color = "green";
/*********************************************************************************************\
 ***** HTML LED color PICK ONLY ONE!
\*********************************************************************************************/
String LED_color = "blue";
//String LED_color = "green";
/*********************************************************************************************\
 ***** Custom Button Names
\*********************************************************************************************/
String custom_service = "Service";
String custom_pool = "Pool";
String custom_spa = "Spa";
String custom_spillover = "Spillover";
String custom_filter = "Filter";
String custom_lights = "Underwater Lts";
String custom_heater1 = "Heater 1";
String custom_valve3 = "Valve 3";
String custom_valve4 = "Valve 4";
String custom_aux1 = "House Light";
String custom_aux2 = "Aux2";
String custom_aux3 = "Patio Light";
String custom_aux4 = "Yard Light";
String custom_aux5 = "Gas Heater";
String custom_aux6 = "Fan";
/*********************************************************************************************\
 ***** LED light variables
\*********************************************************************************************/
int led_check_system = 0;
int led_service = 0;
int led_pool = 0;
int led_spa = 0;
int led_spillover = 0;
int led_filter = 0;
int led_lights = 0;
int led_heater1 = 0;
int led_valve3 = 0;
int led_valve4 = 0;
int led_aux1 = 0;
int led_aux2 = 0;
int led_aux3 = 0;
int led_aux4 = 0;
int led_aux5 = 0;
int led_aux6 = 0;
/*********************************************************************************************\
 ***** LCD Packet variables
\*********************************************************************************************/
int     lcd_air_temp = 0;
int     lcd_salt_level = 0;
int     lcd_pool_temp = 0;
int     lcd_pool_temp_f = 0;
int     lcd_pool_temp_c = 0;
int     lcd_chlorinator_value = 0;
String  lcd_filter_speed = "";
String  lcd_heater_status = "";
String  lcd_weekday = "";
String  lcd_day_of_week = "";
String  lcd_aqua_time = "";
String  line1;
String  line2;
String lcd_aux1_btn = "OFF";
String lcd_aux2_btn = "OFF";
String lcd_aux3_btn = "OFF";
String lcd_aux4_btn = "OFF";
String lcd_aux5_btn = "OFF";
String lcd_aux6_btn = "OFF";




// int salt_level = 0;
// String heater1_status;
// int filter_speed = 0;
// int pool_temp = 0;
// int air_temp = 0;
// int pool_chlorinator = 0;
// String day_of_week = "";
// String aqua_time = "";
// int hour_min = 0;
// int hour = 0;
// int minute = 0;
// String ampm = "";




