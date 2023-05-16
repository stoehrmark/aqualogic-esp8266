uint8_t btn_hex_aux1[] = {0x10, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x18, 0x10, 0x03};
uint8_t btn_hex_aux2[] = {0x10, 0x02, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1C, 0x10, 0x03};
uint8_t btn_hex_aux3[] = {0x10, 0x02, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x24, 0x10, 0x03};
uint8_t btn_hex_aux4[] = {0x10, 0x02, 0x00, 0x02, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x34, 0x10, 0x03};
uint8_t btn_hex_aux5[] = {0x10, 0x02, 0x00, 0x02, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x54, 0x10, 0x03};
uint8_t btn_hex_aux6[] = {0x10, 0x02, 0x00, 0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x94, 0x10, 0x03};

// Define constants for the array sizes
const int btn_hex_aux1_size = sizeof(btn_hex_aux1) / sizeof(btn_hex_aux1[0]);
const int btn_hex_aux2_size = sizeof(btn_hex_aux2) / sizeof(btn_hex_aux2[0]);
const int btn_hex_aux3_size = sizeof(btn_hex_aux3) / sizeof(btn_hex_aux3[0]);
const int btn_hex_aux4_size = sizeof(btn_hex_aux4) / sizeof(btn_hex_aux4[0]);
const int btn_hex_aux5_size = sizeof(btn_hex_aux5) / sizeof(btn_hex_aux5[0]);
const int btn_hex_aux6_size = sizeof(btn_hex_aux6) / sizeof(btn_hex_aux6[0]);

// Define an enum to represent the different buttons
enum Button {
  AUX1,
  AUX2,
  AUX3,
  AUX4,
  AUX5,
  AUX6
};

Button selectedButton = AUX1;

void handleForm() {
  if (server.hasArg("control_btn")) {
    String control_btn = server.arg("control_btn");
    
    if (control_btn == "aux1") {
      selectedButton = AUX1;
    } else if (control_btn == "aux2") {
      selectedButton = AUX2;
    } else if (control_btn == "aux3") {
      selectedButton = AUX3;
    } else if (control_btn == "aux4") {
      selectedButton = AUX4;
    } else if (control_btn == "aux5") {
      selectedButton = AUX5;
    } else if (control_btn == "aux6") {
      selectedButton = AUX6;
    }
    
    btn_send_yes = 1;

    server.sendHeader("Location", "/");
    server.send(302);
  } else {
    server.send(400, "text/html", "Missing parameters");
  }
}

void send_btn_command() {
  if (btn_send_yes == 1) {
    uint8_t* btn_command_to_send;
    int btn_command_size;
    
    // Set the appropriate button command based on the selectedButton
    switch (selectedButton) {
      case AUX1:
        btn_command_to_send = btn_hex_aux1;
        btn_command_size = btn_hex_aux1_size;
        break;
      case AUX2:
        btn_command_to_send = btn_hex_aux2;
        btn_command_size = btn_hex_aux2_size;
        break;
      case AUX3:
        btn_command_to_send = btn_hex_aux3;
        btn_command_size = btn_hex_aux3_size;
        break;
      case AUX4:
        btn_command_to_send = btn_hex_aux4;
        btn_command_size = btn_hex_aux4_size;
        break;
      case AUX5:
        btn_command_to_send = btn_hex_aux5;
        btn_command_size = btn_hex_aux5_size;
        break;
      case AUX6:
        btn_command_to_send = btn_hex_aux6;
        btn_command_size = btn_hex_aux6_size;
        break;
    }
    
    for (int i = 0; i < 3; i++) {
      delayMicroseconds(600); // Delay between each byte
      Serial.print(i);
       Serial.print(" btn_command_to_send: ");     
      for (int ii = 0; ii < btn_command_size; ii++) {
        RS485Serial.write(btn_command_to_send[ii]); // Send the byte value
        Serial.print(btn_command_to_send[ii]);
        Serial.print(" ");
      }
      Serial.println();
    }
    
    btn_send_yes = 0;
  }
}
