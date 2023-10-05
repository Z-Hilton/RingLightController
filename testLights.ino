#include <Adafruit_NeoPixel.h>

#define LED_PIN 15      // Pin connected to the Data Input of WS2812B
#define NUM_LEDS 24     // Number of WS2812B LEDs in the strip
#define BRIGHTNESS 200  // Set the brightness (0-255)

#define SHUTTER_PIN 14  //Pin connected to the shutter signal of the cameras via 3.5mm jack
Adafruit_NeoPixel strip;

void setup() {
  // setup code here, to run once:
  pinMode(23, OUTPUT); // set each bank of 6 White Leds as outputs
  pinMode(21, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(2, OUTPUT);                                                                                                                                                                                                                                                                                 
  // set the shutterPin as a normally-high input
  pinMode(SHUTTER_PIN, INPUT_PULLUP); 
  // To control rgb leds
  strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800); 
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show();  // Initialize all pixels to off


  // analogWrite(23, 50); 
  // analogWrite(21, 50);
  // analogWrite(19, 50);
  // analogWrite(5, 50);
  // analogWrite(16, 50);
  // analogWrite(2, 50);
}

void loop() {
  //main code here, to run repeatedly:
  // if the shutter signal drops, flash on and off very fast (no delay)
  if (digitalRead(SHUTTER_PIN) == 0) { 
    digitalWrite(23, HIGH);
    digitalWrite(21, HIGH);
    digitalWrite(19, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(2, HIGH);
    delay(10); 
    digitalWrite(23, LOW);
    digitalWrite(21, LOW);
    digitalWrite(19, LOW);
    digitalWrite(5, LOW);
    digitalWrite(16, LOW);
    digitalWrite(2, LOW);
    delay(500);
    //Set the brightness of the LEDS to low (for cameras to focus)
    // analogWrite(23, 50); 
    // analogWrite(21, 50); //seems to cause the board to heat up...
    // analogWrite(19, 50);
    // analogWrite(5, 50);
    // analogWrite(16, 50);
    // analogWrite(2, 50);
  }
}
