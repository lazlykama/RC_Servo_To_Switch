#include <Arduino.h>

// PWM caracteristic
#define MIN_DUTY 0.06
#define MAX_DUTY 0.125
#define BORDER_DUTY 0.10
#define ERROR 0.01

// PIN config
#define SERVO_INPUT_PIN PB0
#define SWITCH_OUTPUT_PIN_1 PB2
#define SWITCH_OUTPUT_PIN_2 PB4
#define LED_OUTPUT_PIN PB1

void turn_off() {
  digitalWrite(SWITCH_OUTPUT_PIN_1, LOW);
  digitalWrite(SWITCH_OUTPUT_PIN_2, LOW);
  digitalWrite(LED_OUTPUT_PIN, LOW);
}

void turn_on() {
  digitalWrite(SWITCH_OUTPUT_PIN_1, HIGH);
  digitalWrite(SWITCH_OUTPUT_PIN_2, HIGH);
  digitalWrite(LED_OUTPUT_PIN, HIGH);
}

void setup() {
  // Generic setup
  pinMode(SERVO_INPUT_PIN, INPUT);
  pinMode(SWITCH_OUTPUT_PIN_1, OUTPUT);
  pinMode(SWITCH_OUTPUT_PIN_2, OUTPUT);
  pinMode(LED_OUTPUT_PIN, OUTPUT);
  turn_off();
  // Some lifesign about we are running and waiting the input
  for (int i=0; i < 3; i++) {
    digitalWrite(LED_OUTPUT_PIN, HIGH);
    delay(150);
    digitalWrite(LED_OUTPUT_PIN, LOW);
    delay(150);
  }
}

void loop() {
  // Read input
  unsigned long lowTime = pulseIn(SERVO_INPUT_PIN, LOW, 1000000);
  unsigned long highTime = pulseIn(SERVO_INPUT_PIN, HIGH, 1000000);
  unsigned long cycleTime = highTime + lowTime;
  if (cycleTime > 0) {
    float dutyCycle = (float)highTime / float(cycleTime);
    if (dutyCycle >= MAX_DUTY + ERROR) {
      // Turn off because error
      turn_off();
    } else if (dutyCycle >= BORDER_DUTY) {
      // Turn on because PWM duty over the limit
      turn_on();
    } else {
      // Turn off otherwise
      turn_off();
    }
  } else {
    // Turn off because no acceptable cycle time arrived
    turn_off();
  }
}
