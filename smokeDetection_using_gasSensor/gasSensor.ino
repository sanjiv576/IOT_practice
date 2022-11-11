const int redLed = 10, greenLed = 8, buzzerPin = 7;
const int gasSensorPin = A0;
const int harmfulSmokeVal = 603;
int smokeValue;
void setup(){
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(gasSensorPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  
  smokeValue = analogRead(gasSensorPin);
  Serial.print("Smoke value: ");
  Serial.println(smokeValue);
  delay(1000);
  
  if(smokeValue > harmfulSmokeVal){
    tone(buzzerPin, 1000, 2000, 1000, 2000);
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    Serial.println("Warning ! : Smoke detected");
    
    // do rest of things like open the emergency exits/doors
  }
  
  else {
    
    noTone(buzzerPin);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    Serial.println("Safe !!!");
  }
}




// Note: https://www.tinkercad.com/things/7I42M4oIw5f-grand-esboo/editel?tenant=circuits