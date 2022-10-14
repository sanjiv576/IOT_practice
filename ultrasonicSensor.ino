const int trigPin = 8;
const int echoPin = 7;
const int motorPin = 9;
int timeTaken;
int cm = 0;
int inch = 0;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, INPUT);
  Serial.begin(9600);
}


void loop(){
// for starting ultrasonic sensor  to send sound wave
  digitalWrite(trigPin, LOW);
  // delay(1);
  digitalWrite(trigPin, HIGH);
  // delay(1);
  
  
  timeTaken = pulseIn(echoPin, HIGH);
  
  Serial.print("Time : ");
  Serial.println(timeTaken);
  
  cm = 0.01723 * timeTaken;
  Serial.print("Distance in cm : ");
  Serial.println(cm);
  
  if( cm > 50){
    digitalWrite(motorPin, HIGH);
    Serial.println("Motor on");
  }
  else { 
    digitalWrite(motorPin, LOW);
    Serial.println("Motor off");
  }
}