// String btn_hex_aux1 = "10 02 00 83 01 00 02 00 00 00 02 00 00 00 00 9A 10 03";
// String btn_hex_aux2 = "10 02 00 83 01 00 04 00 00 00 04 00 00 00 00 9E 10 03";
String btn_hex_aux1 = "10 02 00 02 00 02 00 00 00 02 00 00 00 18 10 03";
String btn_hex_aux2 = "10 02 00 02 00 04 00 00 00 04 00 00 00 1C 10 03";
String btn_hex_aux3 = "10 02 00 02 00 08 00 00 00 08 00 00 00 24 10 03";
String btn_hex_aux4 = "10 02 00 02 00 10 00 00 00 00 10 00 00 00 00 34 10 03";
String btn_hex_aux5 = "10 02 00 02 00 20 00 00 00 20 00 00 00 54 10 03";
String btn_hex_aux6 = "10 02 00 02 00 40 00 00 00 40 00 00 00 94 10 03";
void handleForm() {
if (server.hasArg("control_btn")) {// && server.hasArg("parameter2")
      String control_btn = server.arg("control_btn");
      if (control_btn == "aux1"){
      btn_command_to_send = btn_hex_aux1;
      btn_send_yes = 1;
      } else if (control_btn == "aux2"){
      btn_command_to_send = btn_hex_aux2;
      btn_send_yes = 1;
      } else if (control_btn == "aux3"){
      btn_command_to_send = btn_hex_aux3;
      btn_send_yes = 1;
      } else if (control_btn == "aux4"){
      btn_command_to_send = btn_hex_aux4;
      btn_send_yes = 1;
      } else if (control_btn == "aux5"){
      btn_command_to_send = btn_hex_aux5;
      btn_send_yes = 1;
      } else if (control_btn == "aux6"){
      btn_command_to_send = btn_hex_aux6;
      btn_send_yes = 1;
      }

  //     Serial.print("btn_command_to_send: ");
  // Serial.println(btn_command_to_send);
  //     Serial.print("btn_send_yes: ");
  // Serial.println(btn_send_yes);

    //String param2 = server.arg("parameter2");
    // Send a response back to the client
    //server.send(200, "text/html", "Received parameters: " + control_btn);// + ", " + param2
    server.sendHeader("Location", "/");
    server.send(302);
  } else {
    server.send(400, "text/html", "Missing parameters");
  }
}
void send_btn_command(){
if(btn_send_yes == 1){
  for (int i = 0; i < 10; i++) {
RS485Serial.print(btn_command_to_send);

  //RS485Serial.write(btn_command_to_send.c_str());
  Serial.print("RS485Serial.write: ");
  Serial.println(btn_command_to_send);
  delay(10);
  }
  btn_send_yes = 0;
}
}