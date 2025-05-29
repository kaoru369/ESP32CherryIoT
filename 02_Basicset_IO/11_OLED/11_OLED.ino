#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> //by Adafruit

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Wire.begin(1, 3); //(SDA, SCL) 1,3:ConnectorA 5,4:ConnectorB

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for(;;); //Infinite loop when screen initialization fails
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 5);
  display.print(F("Hello"));
  display.setCursor(0, 15);
  display.print(F("ESP32"));
  display.setCursor(0, 25);
  display.print(F("CherryIoT"));
  
}

void loop()
{
  for(int i=0; i<65; i++){
      display.clearDisplay();

      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);

      display.setCursor(35, 5);
      display.print(F("Hello"));

      display.setCursor(35, 15);
      display.print(F("ESP32"));

      display.setCursor(i, 30);
      display.print(F("CherryIoT"));

      display.setTextSize(2);
      display.setCursor(i, 45);
      display.print(F("owata"));
      display.display();
      delay(20);
  }
}