#include <Servo.h>

#define trigPin1 8
#define echoPin1 9
#define trigPin2 10
#define echoPin2 11
#define ledPin 7
#define servoPin 13

Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  myservo.attach(servoPin);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance = duration / 58.8;
  Serial.print("Distance from ultrasonic sensor 1: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 10) {
    myservo.write(90);
    } else {
      myservo.write(0);
    } // 3초 대기

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance = duration / 58.8;
  Serial.print("Distance from ultrasonic sensor 2: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 20) { 
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(1000); 
}
