#include "Radio.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 8); // CE, CSN
const byte address[10] = "ADDRESS01";

void Radio::begin(){
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  Serial.println("Radio begin");
}

void Radio::Send(){
}

void Radio::receive(){
}