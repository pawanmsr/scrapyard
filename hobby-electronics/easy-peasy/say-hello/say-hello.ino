#include <Servo.h>

Servo myServo;

const int pirPin = 10;
const int servoPin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pirPin, INPUT); 
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  wave(isHuman(1000, 100));
  delay(1000);
}

int isHuman(int miliseconds, const int steps) {
  int count = 0;
  while (miliseconds) {
    int data = digitalRead(pirPin);
    Serial.println(data); // Debug.
    
    if (data) count++;
    delay(steps);
    miliseconds = max(miliseconds - steps, 0);
  }

  if (count > 4) return count;
  return 0;
}

void wave(int times) {
  while (times--) {
    myServo.write(60);
    delay(200);
    myServo.write(120);
    delay(200);
  }
}
