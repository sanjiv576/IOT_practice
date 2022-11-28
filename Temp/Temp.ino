
// import library : before this download DHT library and adafruit unified sensor
#include <DHT.h>

// define the pin at 5
#define DHTPIN 5

// define dht type 
#define DHTTYPE DHT22

// initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

float hum , temp;

void setup() {
  Serial.begin(9600);
  Serial.println("Started");
  
}

void loop() {
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  Serial.print("Temp in C: ");
  Serial.println(temp);

  Serial.print("Humi in C: ");
  Serial.println(hum);
  delay(2000);
}
