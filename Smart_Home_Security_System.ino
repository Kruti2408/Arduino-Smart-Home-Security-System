//--------------- SERVO MOTOR & IR SENSORS ---------------//
#include <Servo.h>

Servo tap_servo;

int IR1 = 4;
int tap_servo_pin =5;
int IR2 = 6;
int val1;
int val2;


//--------------- ULTRASONIC SENSOR ---------------//

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer1 = 11;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;


//--------------- FIRE SENSOR ---------------//

const int buzzer2 = 7; 
const int fireSensorPin = 8;


// * * * * * * * * * * * * * * VOID SETUP * * * * * * * * * * * * * * // 


void setup() {

//--------------- ULTRASONIC SENSOR ---------------//

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer1, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication


//--------------- FIRE SENSOR ---------------//

pinMode(buzzer2, OUTPUT);
pinMode(fireSensorPin, INPUT);

//--------------- SERVO MOTOR & IR SENSORS ---------------//

pinMode(IR1,INPUT);
pinMode(IR2,INPUT);
tap_servo.attach(tap_servo_pin);

}


// * * * * * * * * * * * * * * VOID LOOP * * * * * * * * * * * * * * // 


void loop() {

//--------------- ULTRASONIC SENSOR ---------------//

// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
  if (safetyDistance <= 15)
    {
    digitalWrite(buzzer1, HIGH);
    digitalWrite(ledPin, HIGH);
    //tone(buzzer1, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer1);     // Stop sound...
    delay(1000);        // ...for 1sec
  }
  else {
    digitalWrite(buzzer1, LOW);
    digitalWrite(ledPin, LOW);
  }

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);


//--------------- FIRE SENSOR ---------------//

int fireValue = digitalRead(fireSensorPin);
Serial.print(fireValue);
//delay(1000);
  if (fireValue == 1) 
  {
    digitalWrite(buzzer2, HIGH);
    //delay(6000);
    tone(buzzer2, 1000); // Send 1KHz sound signal...
    delay(2000);        // ...for 1 sec
    noTone(buzzer2);     // Stop sound...
    delay(2000);        // ...for 1sec

  }
  else {
    digitalWrite(buzzer2, LOW);
  }
delay(500);


//--------------- SERVO MOTOR & IR SENSORS ---------------//

// IR SENSOR : 1 

val1 = digitalRead(IR1);
Serial.println(val1);
  if (val1==0)
  {
    tap_servo.write(0);
    delay(3000);
    tap_servo.write(180);
  }

// IR SENSOR : 2 

val2 = digitalRead(IR2);
Serial.println(val2);
  if (val2==0)
  {
    tap_servo.write(0);
    delay(3000);
    tap_servo.write(180);
  }

}
