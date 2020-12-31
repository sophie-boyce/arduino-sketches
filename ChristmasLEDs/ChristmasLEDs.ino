
/*
    ChristmasLEDs
    
    This sketch gradually lights up an LPD8806 LED strip from one side to the other with 
    a Christmas color. After this color has reached the end of the LED strip, the strip does a
    slow transition to white from the start to the end of the LED strip before switching to another
    Christmas color and repeating.

    The circuit:
    * Connect the Black Ground wire on your LED strip to any ground pin on your Arduino.
    * Connect the Yellow Clock wire on your LED strip to digital Pin 3 on your Arduino.
    * Conncect the Green Data wire on your LED strip to digital Pin 2 on your Arduino.
    * Connect the Red +5V power wire on your LED strip to your 5V power supply.

    Created 29 December 2020
    By Sophia Boyce

    https://learn.adafruit.com/digital-led-strip/overview
    
  */

#include "LPD8806.h"
#include "SPI.h"

int numberOfLEDs = 160;

int dataPin = 2;
int clockPin = 3;

LPD8806 strip = LPD8806(numberOfLEDs, dataPin, clockPin);

uint32_t red = strip.Color(255, 0, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t gold = strip.Color(232, 162, 0);
uint32_t white = strip.Color(255, 255, 255);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  animationAndTransition(red);
  animationAndTransition(green);
  animationAndTransition(gold);
}

void animationAndTransition(uint32_t color){
  chasingColorAnimation(color, 10);
  chasingColorAnimation(white, 100);
}

void chasingColorAnimation(uint32_t color, uint8_t delay_time){
  int i;

  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(delay_time);
  }
}



