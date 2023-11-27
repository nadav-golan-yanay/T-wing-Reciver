#include "Screen.h"
#include <SPI.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789

#define TFT_CS    3
#define TFT_DC    17
#define TFT_SCLK  14
#define TFT_MOSI  13
#define TFT_RST   15

Adafruit_ST7789 *_tft = NULL;

void Screen::Begin(){
  // put your setup code here, to run once:
  SPIClass *spi = new SPIClass(HSPI);
  spi->begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
  _tft = new Adafruit_ST7789(spi, TFT_CS, TFT_DC, TFT_RST);
  // 80MHz should work, but you may need lower speeds
  _tft->setSPISpeed(80000000);
  // this will vary depending on your display
  _tft->init(240, 240, SPI_MODE2);
  _tft->fillScreen(0x0002);
  _tft->setRotation(2);     //to 90 deg
  _tft->setTextSize(2); //1 is default 6x8, 2 is 12x16, 3 is 18x24
  Serial.println("Finish SetUp");
}