#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
int motor1pin1 = 4;
int motor1pin2 = 5;
int motor2pin1 = 6;
int motor2pin2 = 7;
int motor3pin1 = 2;
int motor3pin2 = 3;
void setup() {
  // put your setup code here, to run once:
  Dabble.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Dabble.processInput();
  if(GamePad.isUpPressed()) {
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
  } else if(GamePad.isDownPressed()) {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
  } else if(!GamePad.isUpPressed() && !GamePad.isDownPressed()) {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
  }
  if(GamePad.isTrianglePressed()) {
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
  } else if(GamePad.isCrossPressed()) {
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
  } else if(!GamePad.isTrianglePressed() && !GamePad.isCrossPressed()) {
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
  }
  if(GamePad.isStartPressed()) {
    digitalWrite(motor3pin1, HIGH);
    digitalWrite(motor3pin2, LOW);
  } else if(!GamePad.isStartPressed()) {
    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, LOW);
  }
  delay(100);
}
