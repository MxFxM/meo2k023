#include <Arduino.h>
#include <FastLED.h>

#define BUTTON_PIN 14

#define RGB_PIN       4
#define RGB_LED_NUM   11
#define BRIGHTNESS    50
#define CHIP_SET      WS2812B
#define COLOR_CODE   GRB

CRGB LEDs[RGB_LED_NUM];

void buttonWait(void);
void lightUpLEDs(int numLEDs);
void blinkLEDs(int numLEDs, int times);
void turnOffLEDs(void);
int penisLengthCalculator();

void setup() {
  pinMode(BUTTON_PIN, INPUT);

  FastLED.addLeds<CHIP_SET, RGB_PIN, COLOR_CODE>(LEDs, RGB_LED_NUM);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  buttonWait();

  int penisLength = penisLengthCalculator();
  lightUpLEDs(penisLength);
  blinkLEDs(penisLength, 5);
  turnOffLEDs();
}

void buttonWait() {
  while (digitalRead(BUTTON_PIN) == LOW) {
    // Do nothing
  }
}

void lightUpLEDs(int numLEDs) {
  for (int i = 0; i < numLEDs; i++) {
    LEDs[i] = CRGB(0, 255, 0); // Set the color to green
    FastLED.show();
    delay(random(100, 1000)); // Delay between 0.1 and 1 second
  }
}

void blinkLEDs(int numLEDs, int times) {
  for (int t = 0; t < times; t++) {
    for (int i = 0; i < numLEDs; i++) {
      LEDs[i] = CRGB(0, 255, 0); // Set the color to green
    }
    FastLED.show();

    delay(100);

    for (int i = 0; i < numLEDs; i++) {
      LEDs[i] = CRGB(0, 0, 0); // Set the LED off
    }
    FastLED.show();

    delay(100);
  }
}

void turnOffLEDs() {
  for (int i = 0; i < RGB_LED_NUM; i++) {
    LEDs[i] = CRGB(0, 0, 0); // Set the LED off
    FastLED.show();
  }
}

int penisLengthCalculator() {
  // this is fixed for 11 leds
  int randomnumber = random(0, 100);

  if (randomnumber <= 2) {
    return 1;
  }

  if (randomnumber <= 4) {
    return 2;
  }

  if (randomnumber < 7) {
    return 3;
  }

  if (randomnumber < 12) {
    return 4;
  }

  if (randomnumber < 18) {
    return 5;
  }

  if (randomnumber < 43) {
    return 6;
  }

  if (randomnumber < 64) {
    return 7;
  }

  if (randomnumber < 76) {
    return 8;
  }

  if (randomnumber < 88) {
    return 9;
  }

  if (randomnumber < 97) {
    return 10;
  }

  return 11;
}