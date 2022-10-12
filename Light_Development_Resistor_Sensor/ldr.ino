const int ldrSensorPin = A2;
const int ledPin = 7;
float sensorValue;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  
  sensorValue = analogRead(ldrSensorPin);
  Serial.print("Analog reading : ");
  Serial.println(sensorValue);
  
  if (sensorValue > 224){
    
    digitalWrite(ledPin, HIGH);
    Serial.println("LED is on");
    
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  // delay(2000);
}

