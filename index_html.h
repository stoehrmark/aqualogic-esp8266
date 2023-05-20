#ifndef INDEX_HTML_H
#define INDEX_HTML_H

const char* index_html = R"=====(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Aqualogic Control Panel</title>
    <link href='https://fonts.googleapis.com/css?family=VT323' rel='stylesheet' type='text/css'>
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <style>
      body {
        color: #FFFFFF;
        display: flex;
        justify-content: center;
        align-items: center;
        background-color: #D3D3D3;
        color: #FFFFFF
      }

      .container {
        border: 6px solid #808080;
        border-radius: 20px;
        padding: 20px;
        display: flex;
        flex-direction: column;
        background-color: black;
        width: 40vw;
        text-align: center;
	    box-shadow: 10px 10px 10px 0px rgba(0,0,0,0.3);
		filter: drop-shadow(10px 10px 10px rgba(0,0,0,0.3));
      }

      .row {
        display: flex;
        flex-direction: row;
      }

      .info {
		font-size: smaller;
        display: flex;
        flex-direction: row;
		flex-wrap: wrap;
        justify-content: space-evenly;
        align-items: center;
      }

      .col {
        flex: 1;
      }

      .function_btn {
        border: 3px solid white;
        border-radius: 10px;
        margin: 5px;
        display: flex;
        flex-direction: row;
        justify-content: center;
        align-items: center;
        height: 50px;
      }

      .led,
      ._button {
        width: 18px;
        height: 18px;
        border-radius: 50%;
        border: 1px solid #353636;
      }

      .led.blink {
        animation: blinking-led 1s step-start infinite;
      }

      @keyframes blinking-led {
        50% {
          box-shadow: inset 0 2px 2px #e6e6e6, inset 1px 0 2px #848484,
            inset -1px 0 2px #4f4f4f, inset 0 -1px 1px #2f2f2f,
            0 0 2px rgba(0, 0, 0, 0.24);
          background: linear-gradient(#fff, #484848);
        }
      }

      ._button.black {
        box-shadow: inset 0 2px 2px #c9c9c9, inset 1px 0 2px #bfbfbf,
          inset -1px 0 2px #c2c2c2, inset 0 -1px 1px #b8b8b8,
          0 0 2px rgba(0, 0, 0, 0.24);
        background: linear-gradient(to bottom, #5e5e5e, #000000);
      }

      .led.green {
        box-shadow: inset 0 2px 2px #f0ffed, inset 1px 0 2px #48ff00,
          inset -1px 0 2px #70e17a, inset 0 -1px 1px #2a5524,
          0 0 2px rgba(0, 0, 0, 0.24);
        background: linear-gradient(#0cff34, #25b92c);
      }

      .led.blue {
        box-shadow: inset 0 2px 2px #d3eefc, inset 1px 0 2px #1e90ff,
          inset -1px 0 2px #3a70b3, inset 0 -1px 1px #0b1d37,
          0 0 2px rgba(0, 0, 0, 0.24);
        background: linear-gradient(#1e90ff, #0b1d37);
      }

      .led.red {
        box-shadow: inset 0 2px 2px #fbb, inset 1px 0 2px #f00,
          inset -1px 0 2px #e17070, inset 0 -1px 1px #5e2525,
          0 0 2px rgba(0, 0, 0, 0.24);
        background: linear-gradient(#ff2323, #b90000);
      }

      .led.orange {
        box-shadow: inset 0 2px 2px rgb(233, 172, 122), inset 1px 0 2px rgb(255, 102, 0),
          inset -1px 0 2px #e77e4d, inset 0 -1px 1px #5e4125,
          0 0 2px rgba(0, 0, 0, 0.24);
        background: linear-gradient(#fc6711, #b95300);
      }

      .led.off {
        box-shadow: inset 0 2px 2px #e6e6e6, inset 1px 0 2px #848484,
          inset -1px 0 2px #4f4f4f, inset 0 -1px 1px #2f2f2f,
          0 0 2px rgba(0, 0, 0, 0.24);
        background: linear-gradient(#fff, #484848);
      }

      .lcd_display_area {
        border-radius: 5px;
        flex: 2;
        display: flex;
        justify-content: center;
        align-items: center;
        margin: 5px;
        font-family: VT323;
        min-height: 50px;
        font-size: calc(1vw + 1vh + 1vmin);
        line-height: .7;
      }
	  .lcd_display_area.green {
		border: 2px solid green;
		background-color: #98FB98;
		color: black;
	  }
	  .lcd_display_area.red {
		border: 2px solid red;
		background-color: #fb9898;
		color: black;
	  }
      .check_system_area {
        flex: .5;
        display: flex;
        flex-direction: row;
        justify-content: center;
        align-items: center;
        gap: 10px;
        padding: 5px;
      }

      .menu_input_area {
        flex: 1;
        display: flex;
        flex-direction: row;
        justify-content: center;
        align-items: center;
      }

      @media screen and (max-width: 768px) {
        .container {
          width: 99vw;
        }
        .row {
          flex-direction: column;
        }
        .col {
          flex: auto;
        }
        .info {
          flex-direction: column;
        }
      }
    </style>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
  <script>
    $(document).ready(function() {
      setInterval(function() {
        $.ajax({
          url: "/ajax",
          type: "GET",
          dataType: "json",
          success: function(response) {
            $("#lcd_line1").text(response.lcd_line1);
            $("#lcd_line2").text(response.lcd_line2);
            //console.log(response);

          var $lcd_display_area = $("#lcd_display_area");
          $lcd_display_area.removeClass("green red");
          $lcd_display_area.addClass(response.lcd_display_area);
          var $led_check_system = $("#led_check_system");
          $led_check_system.removeClass("green blue red orange off blink");
          $led_check_system.addClass(response.led_check_system);
          var $led_service = $("#led_service");
          $led_service.removeClass("green blue red orange off blink");
          $led_service.addClass(response.led_service);
          var $led_pool = $("#led_pool");
          $led_pool.removeClass("green blue red orange off blink");
          $led_pool.addClass(response.led_pool);
          var $led_spa = $("#led_spa");
          $led_spa.removeClass("green blue red orange off blink");
          $led_spa.addClass(response.led_spa);
          var $led_spillover = $("#led_spillover");
          $led_spillover.removeClass("green blue red orange off blink");
          $led_spillover.addClass(response.led_spillover);
          var $led_filter = $("#led_filter");
          $led_filter.removeClass("green blue red orange off blink");
          $led_filter.addClass(response.led_filter);
          var $led_lights = $("#led_lights");
          $led_lights.removeClass("green blue red orange off blink");
          $led_lights.addClass(response.led_lights);
          var $led_heater1 = $("#led_heater1");
          $led_heater1.removeClass("green blue red orange off blink");
          $led_heater1.addClass(response.led_heater1);
          var $led_valve3 = $("#led_valve3");
          $led_valve3.removeClass("green blue red orange off blink");
          $led_valve3.addClass(response.led_valve3);
          var $led_valve4 = $("#led_valve4");
          $led_valve4.removeClass("green blue red orange off blink");
          $led_valve4.addClass(response.led_valve4);
          var $ledAux1 = $("#led_aux1");
          $ledAux1.removeClass("green blue red orange off blink");
          $ledAux1.addClass(response.led_aux1);
          var $ledAux2 = $("#led_aux2");
          $ledAux2.removeClass("green blue red orange off blink");
          $ledAux2.addClass(response.led_aux2);
          var $ledAux3 = $("#led_aux3");
          $ledAux3.removeClass("green blue red orange off blink");
          $ledAux3.addClass(response.led_aux3);
          var $ledAux4 = $("#led_aux4");
          $ledAux4.removeClass("green blue red orange off blink");
          $ledAux4.addClass(response.led_aux4);
          var $ledAux5 = $("#led_aux5");
          $ledAux5.removeClass("green blue red orange off blink");
          $ledAux5.addClass(response.led_aux5);
          var $ledAux6 = $("#led_aux6");
          $ledAux6.removeClass("green blue red orange off blink");
          $ledAux6.addClass(response.led_aux6);
          $("#info_pool_temp_f").text(response.lcd_pool_temp_f);
          $("#info_pool_temp_c").text(response.lcd_pool_temp_c);
          $("#info_heater1").text(response.lcd_heater_status);
          $("#info_salt").text(response.lcd_salt_level);


          },
          error: function(jqXHR, textStatus, errorThrown) {
            console.log("AJAX Request Failed: " + textStatus, errorThrown);
          },
          timeout: 5000, // Set a timeout value (in milliseconds)
        });
      }, 1000);
    });
  </script>
  </head>
  <body>
    <div class="container">
      <div class="row">
        <div id="lcd_display_area" class="lcd_display_area $LCD_COLOUR">
          <div class="lcd_display">
            <div class="status_title" id="lcd_line1">$LCD_LINE1</div>
            <div class="status_value" id="lcd_line2">$LCD_LINE2</div>
          </div>
        </div>
        <div class="check_system_area">
          <div>Check<br />System</div>
          <div id="led_check_system" class="led $CHECK_SYSTEM"></div>
        </div>
        <div class="menu_input_area">
      <form method="GET" action="/form">  
			<div><div><button name="control_btn" value="left" type="submit">&lt;</button></div></div>
      </form>
      <form method="GET" action="/form">     
			<div><div><button name="control_btn" value="plus" type="submit">&plus;</button></div>
      </form>
      <form method="GET" action="/form">
      <div><button name="control_btn" value="menu" type="submit">Menu</button></div>
      </form>
      <form method="GET" action="/form">
      <div><button name="control_btn" value="minus" type="submit">&minus;</button></div></div>
      </form>
      <form method="GET" action="/form">   
      <div><div><button name="control_btn" value="right" type="submit">&gt;</button></div></div>
      </form>

		</div>
		</div>
		<div class="row">
        <div class="col">
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_SERVICE</div>
    <div style="flex: 1;">
      <div id="led_service" class="led $SERVICE"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="service" type="submit"></button>
    </div>
  </div>
</form>
<form method="GET" action="/form">
  <div class="function_btn" style="height: 111px;">
    <div style="flex: 3;">$CUSTOM_POOL </br>$CUSTOM_SPA </br>$CUSTOM_SPILLOVER </div>
    <div style="flex: 1;">
      <div id="led_pool" class="led $POOL"></div>
      <div id="led_spa" class="led $SPA"></div>
      <div id="led_spillover" class="led $SPILLOVER"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="pool_spa_spill" type="submit"></button>
    </div>
  </div>
</form>
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_FILTER</div>
    <div style="flex: 1;">
      <div id="led_filter" class="led $FILTER"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="filter" type="submit"></button>
    </div>
  </div>
</form>
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_LIGHTS</div>
    <div style="flex: 1;">
      <div id="led_lights" class="led $LIGHTS"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="lights" type="submit"></button>
    </div>
  </div>
</form>
        </div>
        <div class="col">
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_HEATER1</div>
    <div style="flex: 1;">
      <div id="led_heater1" class="led $HEATER1"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="heater1" type="submit"></button>
    </div>
  </div>
</form>
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_VALVE3</div>
    <div style="flex: 1;">
      <div id="led_valve3" class="led $VALVE3"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="valve3" type="submit"></button>
    </div>
  </div>
</form>
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_VALVE4</div>
    <div style="flex: 1;">
      <div id="led_valve4" class="led $VALVE4"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="valve4" type="submit"></button>
    </div>
  </div>
</form>
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_AUX1</div>
    <div style="flex: 1;">
      <div id="led_aux1" class="led $AUX1"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="aux1" type="submit"></button>
    </div>
  </div>
</form>
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_AUX2</div>
    <div style="flex: 1;">
      <div id="led_aux2" class="led $AUX2"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="aux2" type="submit"></button>
    </div>
  </div>
</form>
        </div>
        <div class="col">
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_AUX3</div>
    <div style="flex: 1;">
      <div id="led_aux3" class="led $AUX3"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="aux3" type="submit"></button>
    </div>
  </div>
</form>
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_AUX4</div>
    <div style="flex: 1;">
      <div id="led_aux4" class="led $AUX4"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="aux4" type="submit"></button>
    </div>
  </div>
</form>
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_AUX5</div>
    <div style="flex: 1;">
      <div id="led_aux5" class="led $AUX5"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="aux5" type="submit"></button>
    </div>
  </div>
</form>
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 3;">$CUSTOM_AUX6</div>
    <div style="flex: 1;">
      <div id="led_aux6" class="led $AUX6"></div>
    </div>
    <div style="flex: 1;">
      <button class="_button black" name="control_btn" value="aux6" type="submit"></button>
    </div>
  </div>
</form>
<form method="GET" action="/form">
  <div class="function_btn">
    <div style="flex: 1;">
		<button name="control_btn" value="_search" type="submit"><i class="fa fa-eye" aria-hidden="true"></i></button>
	</div>
    <div style="flex: 1;">
      <button class="" name="control_btn" value="aux6" type="submit"></button>
    </div>
    <div style="flex: 1;">
      <button class="" name="control_btn" value="_settings" type="submit"><i class="fa fa-wrench" aria-hidden="true"></i></button>
    </div>
  </div>
</form>
        </div>
      </div>
<div class="info">
<div>Pool: <span id="info_pool_temp_f">$INFO_POOL_TEMP_F</span>°F ( <span id="info_pool_temp_c">$INFO_POOL_TEMP_C</span>°C )</div>
<div>Heater Status: <span id="info_heater1">$INFO_HEATER1</span></div>
<div>Salt Level: <span id="info_salt">$INFO_SALT</span> PPM</div>
</div>
    </div>
  </body>
</html>
)=====";

#endif // INDEX_HTML_H
