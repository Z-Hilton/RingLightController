#include <FastLED.h>

#define RGB_LED_PIN 15      // Pin connected to the Data Input of WS2812B
#define NUM_LEDS 24     // Number of WS2812B LEDs in the strip
#define LED_TYPE    WS2812B  // Adjust the LED type accordingly
#define BRIGHTNESS 255  // Set the brightness (0-255)

#define SHUTTER_PIN 34  //Pin connected to the shutter signal of the cameras via 3.5mm jack

CRGB leds[NUM_LEDS];

void setup() {
  // setup code here, to run once:
  pinMode(18, OUTPUT); // set each bank of 6 White Leds as outputs
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(25, OUTPUT);  
  digitalWrite(18, LOW);
  digitalWrite(19, LOW);
  digitalWrite(21, LOW);
  digitalWrite(22, LOW);
  digitalWrite(23, LOW);
  digitalWrite(25, LOW);                                                                                                                                                                                                                                                                               
  // set the shutterPin as a normally-high input
  pinMode(SHUTTER_PIN, INPUT_PULLUP); 
  // To control rgb leds
  FastLED.addLeds<LED_TYPE, RGB_LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(SHUTTER_PIN, INPUT_PULLUP);
  FastLED.clear();  // Turn off all LEDs initially



}

void loop() {
  //main code here, to run repeatedly:
  // if the shutter signal drops, flash on and off
  if (digitalRead(SHUTTER_PIN) != 0) { 
    digitalWrite(18, HIGH);
    digitalWrite(19, HIGH);
    digitalWrite(21, HIGH);
    digitalWrite(22, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(25, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(18, LOW);
    digitalWrite(19, LOW);
    digitalWrite(21, LOW);
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(25, LOW); 
    delay(10);
  } else {
    turnOnRed();
    digitalWrite(18, HIGH);
    digitalWrite(19, HIGH);
    digitalWrite(21, HIGH);
    digitalWrite(22, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(25, HIGH); 
    delay(2); 

    FastLED.clear();
    FastLED.show();
    digitalWrite(18, LOW);
    digitalWrite(19, LOW);
    digitalWrite(21, LOW);
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(25, LOW); 
    delay(10);    
  }

}

void turnOnWhite() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
}
void turnOnRed() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
  }
  FastLED.show();
}
