/*
 * code adapted from https://rudysarduinoprojects.wordpress.com/2019/03/
 * fun with arduino 22
 */

#include <CMRI.h>

#define CMRI_ADDR 25
#define NUM_LEDS      1
#define NUM_STEPS    48
#define BLINK_SPEED  1  // [ms] lower value = faster blinking
#define BLINK_TIMER   45 // [s]needs adjusting to complete the squence
#define TRIGGER_PIN   2
byte led_pin[NUM_LEDS] = {3};
byte sequencer[NUM_LEDS][NUM_STEPS] = {
// 0                   1                   2                   3                   4   
// 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7
   1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,
   };

byte state = 1, transition;
byte n, p, blink_enabled;
unsigned long time_to_change, time_to_switch_off;
CMRI cmri(CMRI_ADDR, 24, 48);
void setup() {
     pinMode(TRIGGER_PIN, INPUT_PULLUP);
  for(n=0; n<NUM_LEDS; n++) {
    pinMode(led_pin[n], OUTPUT);
    digitalWrite(led_pin[n], LOW);
  }
  Serial.begin(9600);
}

void loop() {
  switch(state) {
    case 1:  // idle
      if(digitalRead(TRIGGER_PIN) == LOW) transition = 12;
    break;
    case 2: // blinking for ON_TIME seconds
      if(millis() > time_to_switch_off)   transition = 21;
    break;
  }

  switch(transition) {
    case 12:
      blink_enabled = 1;
      time_to_switch_off = millis() + (unsigned long)BLINK_TIMER * 1000;
      transition = 0;
      state = 2;
    break;
    case 21:
      blink_enabled = 0;
      time_to_change = 0;
      for(n=0; n<NUM_LEDS; n++)
        digitalWrite(led_pin[n], LOW);
      transition = 0;
      state = 1;
    break;
  }

  if (blink_enabled) {
    if (millis() > time_to_change) {
      time_to_change = millis() + (unsigned long)BLINK_SPEED;
      for(n=0; n<NUM_LEDS; n++) {
        digitalWrite(led_pin[n], sequencer[n][p]);
      }
    p = (p + 1) % NUM_STEPS;
    }
  }
}
