#include <Servo.h>

Servo servo;

int trigPin = 7;
int echoPin = 6;

void setup (){
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  servo.attach(5);
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  long duration = pulseIn(echoPin,HIGH);
  long distance = duration * 0.034/2;
  Serial.println(distance);
  if (distance < 10 ){
    servo.write(180);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);

  }
  else{
    servo.write(90);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
  }
  delay(200);
}
