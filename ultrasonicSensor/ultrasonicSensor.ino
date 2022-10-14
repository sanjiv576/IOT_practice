// trigger that sends soundwave 
const int trigPin = 8;

// echo or receiver that receives the soundwave and becomes HIGH
const int echoPin = 7;

// motor declaration
const int motorPin = 9;

// time taken store
int timeTaken;

// for distance 
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
  
  // stores total time taken when echo becomes HIGH when it receives the data
  timeTaken = pulseIn(echoPin, HIGH);
  
  Serial.print("Time : ");
  Serial.println(timeTaken);
  
  // calculate distance
  cm = 0.01723 * timeTaken;
  Serial.print("Distance in cm : ");
  Serial.println(cm);
  
  // on the motor when the object is detected at a distance more than 50 cm 
  if( cm > 50){
    digitalWrite(motorPin, HIGH);
    Serial.println("Motor on");
  }

  // off the motor when the object is detected at a distance less than 50 cm 
  else { 
    digitalWrite(motorPin, LOW);
    Serial.println("Motor off");
  }
}