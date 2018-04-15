int trigPin0 = 2;
int echoPin0 = 3;
int echoPin1 = 5;
int echoPin2 = 6;
// defines variables
long duration0;
int distance0;
long duration1;
int distance1;
long duration2;
int distance2;
void setup() {
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
digitalWrite(12,HIGH);
pinMode(trigPin0, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin0, INPUT);
pinMode(echoPin1, INPUT);
pinMode(echoPin2, INPUT);// Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
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
void loop() 
{ 
  distance0=ultraSonic(trigPin0,echoPin0);
  distance1=ultraSonic(trigPin0,echoPin1);
  distance2=ultraSonic(trigPin0,echoPin2);
    Serial.print("Distance0:");
  Serial.println(distance0);
    Serial.print("Distance1:");
  Serial.println(distance1);
    Serial.print("Distance2: ");
  Serial.println(distance2);

  
}

