uint8_t btn_hex_service[]         = {0x10, 0x02, 0x00, 0x02, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x24, 0x10, 0x03};
uint8_t btn_hex_pool_spa_spill[]  = {0x10, 0x02, 0x00, 0x02, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x94, 0x10, 0x03};
uint8_t btn_hex_filter[]          = {0x10, 0x02, 0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x01, 0x14, 0x10, 0x03};
uint8_t btn_hex_lights[]          = {0x10, 0x02, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x16, 0x10, 0x03};
uint8_t btn_hex_heater1[]         = {0x10, 0x02, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x1C, 0x10, 0x03};
uint8_t btn_hex_valve3[]          = {0x10, 0x02, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x16, 0x10, 0x03};
uint8_t btn_hex_valve4[]          = {0x10, 0x02, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x18, 0x10, 0x03};
uint8_t btn_hex_aux1[]            = {0x10, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x18, 0x10, 0x03};
uint8_t btn_hex_aux2[]            = {0x10, 0x02, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1C, 0x10, 0x03};
uint8_t btn_hex_aux3[]            = {0x10, 0x02, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x24, 0x10, 0x03};
uint8_t btn_hex_aux4[]            = {0x10, 0x02, 0x00, 0x02, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x34, 0x10, 0x03};
uint8_t btn_hex_aux5[]            = {0x10, 0x02, 0x00, 0x02, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x54, 0x10, 0x03};
uint8_t btn_hex_aux6[]            = {0x10, 0x02, 0x00, 0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x94, 0x10, 0x03};

// Define constants for the array sizes
const int btn_hex_service_size = sizeof(btn_hex_service) / sizeof(btn_hex_service[0]);
const int btn_hex_pool_spa_spill_size = sizeof(btn_hex_pool_spa_spill) / sizeof(btn_hex_pool_spa_spill[0]);
const int btn_hex_filter_size = sizeof(btn_hex_filter) / sizeof(btn_hex_filter[0]);
const int btn_hex_lights_size = sizeof(btn_hex_lights) / sizeof(btn_hex_lights[0]);
const int btn_hex_heater1_size = sizeof(btn_hex_heater1) / sizeof(btn_hex_heater1[0]);
const int btn_hex_valve3_size = sizeof(btn_hex_valve3) / sizeof(btn_hex_valve3[0]);
const int btn_hex_valve4_size = sizeof(btn_hex_valve4) / sizeof(btn_hex_valve4[0]);
const int btn_hex_aux1_size = sizeof(btn_hex_aux1) / sizeof(btn_hex_aux1[0]);
const int btn_hex_aux2_size = sizeof(btn_hex_aux2) / sizeof(btn_hex_aux2[0]);
const int btn_hex_aux3_size = sizeof(btn_hex_aux3) / sizeof(btn_hex_aux3[0]);
const int btn_hex_aux4_size = sizeof(btn_hex_aux4) / sizeof(btn_hex_aux4[0]);
const int btn_hex_aux5_size = sizeof(btn_hex_aux5) / sizeof(btn_hex_aux5[0]);
const int btn_hex_aux6_size = sizeof(btn_hex_aux6) / sizeof(btn_hex_aux6[0]);

// Define an enum to represent the different buttons
enum Button {
  SERVICE,
  POOL_SPA_SPILL,
  FILTER,
  LIGHTS,
  HEATER1,
  VALVE3,
  VALVE4,
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
    
    if (control_btn == "service") {
      selectedButton = SERVICE;
    } else if (control_btn == "pool_spa_spill") {
      selectedButton = POOL_SPA_SPILL;
    } else if (control_btn == "filter") {
      selectedButton = FILTER;
    } else if (control_btn == "lights") {
      selectedButton = LIGHTS;
    } else if (control_btn == "heater1") {
      selectedButton = HEATER1;
    } else if (control_btn == "valve3") {
      selectedButton = VALVE3;
    } else if (control_btn == "valve4") {
      selectedButton = VALVE4;
    } else if (control_btn == "aux1") {
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
      case SERVICE:
        btn_command_to_send = btn_hex_service;
        btn_command_size = btn_hex_service_size;
        break;
      case POOL_SPA_SPILL:
        btn_command_to_send = btn_hex_pool_spa_spill;
        btn_command_size = btn_hex_pool_spa_spill_size;
        break;
      case FILTER:
        btn_command_to_send = btn_hex_filter;
        btn_command_size = btn_hex_filter_size;
        break;
      case LIGHTS:
        btn_command_to_send = btn_hex_lights;
        btn_command_size = btn_hex_lights_size;
        break;
      case HEATER1:
        btn_command_to_send = btn_hex_heater1;
        btn_command_size = btn_hex_heater1_size;
        break;
      case VALVE3:
        btn_command_to_send = btn_hex_valve3;
        btn_command_size = btn_hex_valve3_size;
        break;
      case VALVE4:
        btn_command_to_send = btn_hex_valve4;
        btn_command_size = btn_hex_valve4_size;
        break;
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
