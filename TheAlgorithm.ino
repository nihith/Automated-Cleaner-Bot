int trigPin = 2;
int echoPin0 = 9;
int echoPin1 = 10;
int echoPin2 = 11;
int flag;
// defines variables
double dl;
double ds;
double dr;
float clrnc=10;
//Motor A
const int motorPin1  = 4;  // Pin 14 of L293  
//Motor B
const int motorPin3  = 6; // Pin  7 of L293
const int motorPin4  = 7;  // Pin  2 of L293
double ultraSonic(int trigPin,int echoPin)
{
  int distance,duration;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
return distance= duration*0.034/2;
}
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
void setup() {
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin0, INPUT);
    pinMode(echoPin1, INPUT);
    pinMode(echoPin2, INPUT);// Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
}

void loop() {
  ds = ultraSonic(trigPin,echoPin1);
  if(ds>clrnc)
  {
    motorStraight();
  }
  if(ds<clrnc)
  {
    if(flag==0)
    {
      motorLeft();
      motorStraight();
      dr = ultraSonic(trigPin,echoPin2);
      if(dr<clrnc)
      {
        motorLeft();
        flag=1;
      }
      else
      {
          motorRight();
          
          while((dr<clrnc)&&(ds<clrnc))
          {
            motorStraight();
            ds = ultraSonic(trigPin,echoPin1);
            dr = ultraSonic(trigPin,echoPin2);
            }
           if(dr>clrnc)
           {
            motorRight();
            motorStraight();
            motorLeft(); 
           }
      }
    }
    else
    {
      motorRight();
      motorStraight();
      dl = ultraSonic(trigPin,echoPin0);
      if(dl<clrnc)
      {
        motorRight();
        flag=0;
      }
      else
      {
        motorLeft();
        while((dl<clrnc)&&(ds>clrnc))
        {
          motorStraight();
          ds = ultraSonic(trigPin,echoPin1);
          dl = ultraSonic(trigPin,echoPin0);
        }
        if(dl>clrnc)
        {
          motorLeft();
          motorStraight();
          motorRight();
        }
      }
    }
  }
}

