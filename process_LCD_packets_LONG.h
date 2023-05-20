void process_LCD_packets_LONG(byte* hexArray, int arrayLength, String& line1, String& line2) {
/*********************************************************************************************\
 ***** Build line1
\*********************************************************************************************/
 int i = 0;
  // find first letter or number
  while (i < arrayLength && !isAlphaNumeric(hexArray[i])) {
    i++;
  }
  int line1EndIndex = i;
  // find end of line1
  while (line1EndIndex < arrayLength) {
    if (hexArray[line1EndIndex] == 0x20 && hexArray[line1EndIndex + 1] == 0x20) {
      line1EndIndex += 2;
      break;
    }
    line1EndIndex++;
  }
  // copy line1 to string
  line1 = "";
  for (int j = i; j < line1EndIndex; j++) {
    line1 += (char)hexArray[j];
  }
  line1.trim();
/*********************************************************************************************\
 ***** Build line2 and Replace (_ with space)**Temperatures  (º with :)**Time
\*********************************************************************************************/
  i = line1EndIndex;
  while (i < arrayLength && !isAlphaNumeric(hexArray[i])) {
    i++;
  }
  int line2EndIndex = i;
  while (line2EndIndex < arrayLength) {
    if (hexArray[line2EndIndex] == 0x20 && hexArray[line2EndIndex + 1] == 0x20) {
      break;
    }
    line2EndIndex++;
  }
  line2 = "";
  for (int j = i; j < line2EndIndex; j++) {
    if (hexArray[j] == 0x5F) { //replace underscore (_) with space int temps
      line2 += ' ';
    } else if (hexArray[j] == 0xba) { //replace º with colon (:):
      line2 += ':';
    } else {
      line2 += (char)hexArray[j];
    }
  }
  line2.trim();
//   Serial.println(line1);
// Serial.println(line2);
// Serial.println();
/*********************************************************************************************\
 ***** GET INDIVIDUAL VALUES
\*********************************************************************************************/
// HEARTER1
if (line1.indexOf("Heater1") != -1) {
    if (line2.indexOf("Auto") != -1) {
      lcd_heater_status = "Auto Control";
        //Serial.print("Heater1 Status: ");
        //Serial.println(heater1_status);
    } else if (line2.indexOf("Manual Off") != -1) {
      lcd_heater_status = "OFF";
        // Serial.print("Heater1 Status: ");
        // Serial.println(lcd_heater1_status);
    }
// SALT LEVEL
} else if (line1.indexOf("Salt Level") != -1) {
    String salt_level_str = "";
    for (int i = 0; i < line2.length(); i++) {
      char c = line2.charAt(i);
      if (isdigit(c)) {
        salt_level_str += c;
      }
    }
    lcd_salt_level = salt_level_str.toInt();
    // Serial.print("Salt Level: ");
    // Serial.println(lcd_salt_level);
// Filter Speed
} else if (line1.indexOf("Filter Speed") != -1) {
    String filter_speed_str = "";
    for (int i = 0; i < line2.length(); i++) {
      char c = line2.charAt(i);
      if (isdigit(c)) {
        filter_speed_str += c;
      }
    }
    lcd_filter_speed = filter_speed_str.toInt();
    // Serial.print("Filter Speed: ");
    // Serial.println(lcd_filter_speed);
// Pool Temp  
} else if (line1.indexOf("Pool Temp") != -1) {
    String pool_temp_str = "";
    for (int i = 0; i < line2.length(); i++) {
      char c = line2.charAt(i);
      if (isdigit(c)) {
        pool_temp_str += c;
      }
    }
    lcd_pool_temp = pool_temp_str.toInt();
    // Serial.print("Pool Temp: ");
    // Serial.println(lcd_pool_temp);
// Air Temp
} else if (line1.indexOf("Air Temp") != -1) {
    String air_temp_str = "";
    for (int i = 0; i < line2.length(); i++) {
      char c = line2.charAt(i);
      if (isdigit(c)) {
        air_temp_str += c;
      }
    }
    lcd_air_temp = air_temp_str.toInt();
    // Serial.print("Air Temp: ");
    // Serial.println(lcd_air_temp);
// Pool Chlorinator
} else if (line1.indexOf("Pool Chlorinator") != -1) {
    String pool_chlorinator_str = "";
    for (int i = 0; i < line2.length(); i++) {
      char c = line2.charAt(i);
      if (isdigit(c)) {
        pool_chlorinator_str += c;
      }
    }
    lcd_chlorinator_value = pool_chlorinator_str.toInt();
    // Serial.print("Pool Chlorinator: ");
    // Serial.println(lcd_chlorinator_value);    
// Day of Week & Time
} else if (line1.indexOf("Monday") != -1 || line1.indexOf("Tuesday") != -1 || line1.indexOf("Wednesday") != -1 || line1.indexOf("Thursday") != -1 || line1.indexOf("Friday") != -1 || line1.indexOf("Saturday") != -1 || line1.indexOf("Sunday") != -1) {
  lcd_day_of_week = line1;
  lcd_aqua_time = line2;
  // if (line2.indexOf("A") != -1) {
  //   ampm = "AM";
  // } else if (line2.indexOf("P") != -1) {
  //   ampm = "PM";
  // } 
  // int colonIndex = line2.indexOf(":");
  // hour = line2.substring(0, colonIndex).toInt();
  // minute = line2.substring(colonIndex+1, colonIndex+3).toInt();
// AUX1 Button
} else if (line1.indexOf("Aux1") != -1 || line1.indexOf(custom_aux1) != -1) {
    if (line2.indexOf("Turned On") != -1) {
      lcd_aux1_btn = "ON";
        //Serial.print("AUX1 Button: ");
        //Serial.println(lcd_aux1_btn);
    } else if (line2.indexOf("Turned Off") != -1) {
      lcd_aux1_btn = "OFF";
        // Serial.print("AUX1 Button: ");
        // Serial.println(lcd_aux1_btn);
    }
// AUX2 Button
} else if (line1.indexOf("Aux2") != -1 || line1.indexOf(custom_aux2) != -1) {
    if (line2.indexOf("Turned On") != -1) {
      lcd_aux2_btn = "ON";
        //Serial.print("AUX2 Button: ");
        //Serial.println(lcd_aux2_btn);
    } else if (line2.indexOf("Turned Off") != -1) {
      lcd_aux2_btn = "OFF";
        // Serial.print("AUX2 Button: ");
        // Serial.println(lcd_aux2_btn);
    }
// AUX3 Button
} else if (line1.indexOf("Aux3") != -1 || line1.indexOf(custom_aux3) != -1) {
    if (line2.indexOf("Turned On") != -1) {
      lcd_aux3_btn = "ON";
        //Serial.print("AUX3 Button: ");
        //Serial.println(lcd_aux3_btn);
    } else if (line2.indexOf("Turned Off") != -1) {
      lcd_aux3_btn = "OFF";
        // Serial.print("AUX3 Button: ");
        // Serial.println(lcd_aux3_btn);
    }
// AUX4 Button
} else if (line1.indexOf("Aux4") != -1 || line1.indexOf(custom_aux4) != -1) {
    if (line2.indexOf("Turned On") != -1) {
      lcd_aux4_btn = "ON";
        //Serial.print("AUX4 Button: ");
        //Serial.println(lcd_aux4_btn);
    } else if (line2.indexOf("Turned Off") != -1) {
      lcd_aux4_btn = "OFF";
        // Serial.print("AUX4 Button: ");
        // Serial.println(lcd_aux4_btn);
    }
// AUX5 Button
} else if (line1.indexOf("Aux5") != -1 || line1.indexOf(custom_aux5) != -1) {
    if (line2.indexOf("Turned On") != -1) {
      lcd_aux5_btn = "ON";
        //Serial.print("AUX5 Button: ");
        //Serial.println(lcd_aux5_btn);
    } else if (line2.indexOf("Turned Off") != -1) {
      lcd_aux5_btn = "OFF";
        // Serial.print("AUX5 Button: ");
        // Serial.println(lcd_aux5_btn);
    }
// AUX6 Button
} else if (line1.indexOf("Aux6") != -1 || line1.indexOf(custom_aux6) != -1) {
    if (line2.indexOf("Turned On") != -1) {
      lcd_aux6_btn = "ON";
        //Serial.print("AUX6 Button: ");
        //Serial.println(lcd_aux6_btn);
    } else if (line2.indexOf("Turned Off") != -1) {
      lcd_aux6_btn = "OFF";
        // Serial.print("AUX6 Button: ");
        // Serial.println(lcd_aux6_btn);
    }



}

}