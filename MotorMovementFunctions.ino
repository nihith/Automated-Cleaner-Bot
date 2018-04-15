
//L293D
//Motor A
const int motorPin1  = 4;  // Pin 14 of L293
const int motorPin2  = 5;  // Pin 10 of L293
//Motor B
const int motorPin3  = 6; // Pin  7 of L293
const int motorPin4  = 7;  // Pin  2 of L293
void setup()
{
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(2,OUTPUT);
    digitalWrite(2,HIGH);
    pinMode(3,OUTPUT);
    digitalWrite(3,HIGH);
    pinMode(12,OUTPUT);
    digitalWrite(12,HIGH);
    pinMode(13,OUTPUT);
    digitalWrite(13,HIGH);
}   
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4
void motorStop()
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
}
void motorLeft()
{
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(2000);
    motorStop();
}
void motorRight()
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(2000);
    motorStop();
}
void motorStraight()
{
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(2000);
    motorStop();
}
void loop()
{

}

