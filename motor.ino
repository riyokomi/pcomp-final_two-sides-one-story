#include <AFMotor.h>
#include <Servo.h>

int motorspeed = 0;
const int buttonPin = 51;
const int buttonPin1 = 53;
const int ledPin1 = 50;
const int ledPin2 = 46;

int n = LOW;

AF_DCMotor motor(2);
int buttonState = 0;  
int buttonState1 = 0;

//servo
Servo servoA;
int positionA = 0;

//servo2 test
Servo servoB;
int positionB = 0;


void setup()
{  
    motor.setSpeed(0);
 
    motor.run(RELEASE);
    //motor.run(FORWARD);
    pinMode(buttonPin, INPUT);
    pinMode(buttonPin1, INPUT);
    motorspeed = 255; 

    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);

    //servo
    servoA.attach(37);

    //servo2 test
    servoB.attach(36);

}

void loop()
{  
  buttonState = digitalRead(buttonPin);
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState == HIGH) {
    
    motor.setSpeed(motorspeed);
    motor.run(FORWARD);
    digitalWrite(ledPin2, HIGH);
  } 
  else if(buttonState1 == HIGH) {
    motor.setSpeed(motorspeed);
    motor.run(BACKWARD);
    digitalWrite(ledPin1, HIGH);
  }
  else {
    motor.run(RELEASE);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }

  //servo
if(buttonState ==HIGH && positionA < 180 && positionB < 180){
servoA.write(positionA++);
servoB.write(positionB++);
delay(5);
}

if(buttonState1 == HIGH && positionA > 0 && positionB > 0){
servoA.write(positionA--);
servoB.write(positionB--);
delay(5);
}

}


//reference:http://www.instructables.com/id/Servo-Controlled-by-Pushbuttons/?ALLSTEPS
