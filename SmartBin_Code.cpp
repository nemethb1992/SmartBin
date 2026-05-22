#include <Servo.h>

Servo lidServo;

// Szenzor 1 (kéz)
const int trigPin1 = 9;
const int echoPin1 = 10;

// Szenzor 2 (telítettség)
const int trigPin2 = 7;
const int echoPin2 = 8;

// LED-ek
const int redLED = 2;
const int greenLED = 3;

// Szervó
const int servoPin = 6;

bool lidOpen = false;
unsigned long lastDetected = 0;
const int openTime = 3000; // ms

void setup() {

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);

  lidServo.attach(servoPin);
  lidServo.write(0); // zárt

  digitalWrite(redLED, HIGH);
}


float measureDistance(int trigPin, int echoPin){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration =
    pulseIn(echoPin, HIGH);

  float distance =
    duration * 0.034 / 2;

  return distance;
}


void loop() {

  float handDistance =
    measureDistance(trigPin1,
                    echoPin1);

  float fillDistance =
    measureDistance(trigPin2,
                    echoPin2);


bool full = false;


// TELE VAN?
if(fillDistance < 15){

    full = true;

    Serial.println("SZEMETES TELE!");

    // piros LED villog
    digitalWrite(
        redLED,
        (millis()/300)%2
    );

}
else{

    full = false;
}


  // KÉZ ÉRZÉKELÉS
if(handDistance < 15 &&
   !full){

    lidServo.write(90);

    digitalWrite(
        greenLED,HIGH);

    digitalWrite(
        redLED,LOW);

    lidOpen=true;

    lastDetected=
      millis();
}


  // AUTOMATA ZÁRÁS
  if(lidOpen &&
     millis()-lastDetected >
     openTime){

      lidServo.write(0);

      digitalWrite(
        greenLED,LOW);

      digitalWrite(
        redLED,HIGH);

      lidOpen=false;
  }


  delay(100);
}