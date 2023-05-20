void handle_index_html() {
  String content = index_html;

  content.replace("$LCD_COLOUR", LCD_color);

  content.replace("$FILTER", (led_filter == 1) ? LED_color : ((led_filter == 2) ? LED_color + " blink" : "off"));  
  content.replace("$SERVICE", (led_service == 1) ? "red" : ((led_service == 2) ? "red blink" : "off"));
  content.replace("$CHECK_SYSTEM", led_check_system ? "orange blink" : "off");
  content.replace("$POOL", led_pool ? LED_color : "off");
  content.replace("$POOL", led_pool ? LED_color : "off");
  content.replace("$SPA", led_spa ? LED_color : "off");
  content.replace("$SPILLOVER", led_spillover ? LED_color : "off");
  content.replace("$VALVE3", led_valve3 ? LED_color : "off");
  content.replace("$VALVE4", led_valve4 ? LED_color : "off");
  content.replace("$HEATER1", led_heater1 ? LED_color : "off");
  content.replace("$LIGHTS", led_lights ? LED_color : "off");
  content.replace("$AUX1", led_aux1 ? LED_color : "off");
  content.replace("$AUX2", led_aux2 ? LED_color : "off");
  content.replace("$AUX3", led_aux3 ? LED_color : "off");
  content.replace("$AUX4", led_aux4 ? LED_color : "off");
  content.replace("$AUX5", led_aux5 ? LED_color : "off");
  content.replace("$AUX6", led_aux6 ? LED_color : "off");

  content.replace("$LCD_LINE1", line1);
  content.replace("$LCD_LINE2", line2); 
 
  content.replace("$CUSTOM_SERVICE", custom_service);
  content.replace("$CUSTOM_POOL", custom_pool);
  content.replace("$CUSTOM_SPA", custom_spa);
  content.replace("$CUSTOM_SPILLOVER", custom_spillover);
  content.replace("$CUSTOM_FILTER", custom_filter); 
  content.replace("$CUSTOM_LIGHTS", custom_lights);
  content.replace("$CUSTOM_HEATER1", custom_heater1);
  content.replace("$CUSTOM_VALVE3", custom_valve3);
  content.replace("$CUSTOM_VALVE4", custom_valve4);
  content.replace("$CUSTOM_AUX1", custom_aux1); 
  content.replace("$CUSTOM_AUX2", custom_aux2); 
  content.replace("$CUSTOM_AUX3", custom_aux3); 
  content.replace("$CUSTOM_AUX4", custom_aux4);
  content.replace("$CUSTOM_AUX5", custom_aux5);
  content.replace("$CUSTOM_AUX6", custom_aux6); 

  content.replace("$INFO_POOL_TEMP_F", String(lcd_pool_temp_f)); 
  content.replace("$INFO_POOL_TEMP_C", String(lcd_pool_temp_c)); 
  content.replace("$INFO_HEATER1", String(lcd_heater_status)); 
  content.replace("$INFO_SALT", String(lcd_salt_level)); 

  content.replace("$CHIP_ID", String(ESP.getChipId()));
  content.replace("$CPU_FREQ", String(ESP.getCpuFreqMHz()));
  content.replace("$FLASH_CHIP_ID", String(ESP.getFlashChipId()));
  content.replace("$FLASH_CHIP_SIZE", String(ESP.getFlashChipSize()));
  content.replace("$SKETCH_SIZE", String(ESP.getSketchSize()));
  content.replace("$FREE_SKETCH_SPACE", String(ESP.getFreeSketchSpace()));
  content.replace("$RESET_REASON", String(ESP.getResetReason()));
  content.replace("$RESET_INFO", String(ESP.getResetInfo()));
  content.replace("$UPTIME", String(millis() / 1000));
  content.replace("$RS485_Data", String(data));
  server.send(200, "text/html", content);
}

void handleAjaxRequest() {
  String response = "{";
  response += "\"lcd_line1\":\"" + String(line1) + "\", ";
  response += "\"lcd_line2\":\"" + String(line2) + "\", ";
  response += "\"led_check_system\":\"" + String(led_check_system ? "orange blink" : "off") + "\", ";
  response += "\"led_service\":\"" + String((led_service == 1) ? "red" : ((led_service == 2) ? "red blink" : "off")) + "\", ";
  response += "\"led_pool\":\"" + String(led_pool ? LED_color : "off") + "\", ";
  response += "\"led_spa\":\"" + String(led_spa ? LED_color : "off") + "\", ";
  response += "\"led_spillover\":\"" + String(led_spillover ? LED_color : "off") + "\", ";
  response += "\"led_filter\":\"" + String((led_filter == 1) ? LED_color : ((led_filter == 2) ? LED_color + " blink" : "off")) + "\", ";
  response += "\"led_lights\":\"" + String(led_lights ? LED_color : "off") + "\", ";
  response += "\"led_heater1\":\"" + String(led_heater1 ? LED_color : "off") + "\", ";
  response += "\"led_valve3\":\"" + String(led_valve3 ? LED_color : "off") + "\", ";
  response += "\"led_valve4\":\"" + String(led_valve4 ? LED_color : "off") + "\", ";
  response += "\"led_aux1\":\"" + String(led_aux1 ? LED_color : "off") + "\", ";
  response += "\"led_aux2\":\"" + String(led_aux2 ? LED_color : "off") + "\", ";
  response += "\"led_aux3\":\"" + String(led_aux3 ? LED_color : "off") + "\", ";
  response += "\"led_aux4\":\"" + String(led_aux4 ? LED_color : "off") + "\", ";
  response += "\"led_aux5\":\"" + String(led_aux5 ? LED_color : "off") + "\", ";
  response += "\"led_aux6\":\"" + String(led_aux6 ? LED_color : "off") + "\", ";
  response += "\"lcd_display_area\":\"" + String(LCD_color) + "\"";
  response += "}";
  server.send(200, "application/json", response);
}
