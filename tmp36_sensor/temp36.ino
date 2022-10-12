const int temPin = A0;
float adcValue;
float voltage;
float degreeC;

void setup(){
  Serial.begin(9600);
}

void loop(){
  
  // reads analog value from environment between 0 to 1023
  adcValue = analogRead(temPin);
  
  // convert from adc value to voltage value
  voltage = (adcValue * 5)/1023;
  
  // covert from voltage to Celcuius
  degreeC = 100 * voltage - 50;
  
  Serial.print("ADC value : ");
  Serial.println(adcValue);
  
  Serial.print("Voltage value : ");
  Serial.println(voltage);
  
  Serial.print("Celcius : ");
  Serial.println(degreeC);
  
  delay(2000);
  
}