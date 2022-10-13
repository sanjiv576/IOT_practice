
// declartaion of required libraries
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <SD.h>
#include <SPI.h>


// GPS connection

static const int RxPin = 4, TxPin = 3;

// GPS Baud rate

static const uint32_t GPSBaud = 9600;

// SD card select pin

const int chipSelect = 5;

// led
const int led = 7;

// hold GPS data --> longitude, latitude, timestamp
String gpsText;

// GPS write delay counter variable
int gpsCounter = 0;
int gpsttlCounter = 30;

// TinyGPS++ object
TinyGPSPlus gps;

// SoftwareSeial connection to GPS device
SoftwareSerial ss(RxPin, TxPin);


void setup() {
  pinMode(led, OUTPUT);

  Serial.begin(115200);

  //  start SoftwareSerial
  ss.begin(GPSBaud);

  //  initiallize the SD card
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed or not present");
    while (1);
  }
  Serial.println("Card initialized");



  //  blinking to know that we are ready
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);

  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);

  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
}

void loop() {
  //   turn off the led just in case
  digitalWrite(led, LOW);

  //  see if data is available
  while (ss.available() > 0) {
    if (gps.encode(ss.read())) {

      //      check whthere we have complete GPS location data
      if (displayInfo() != "0") {

        //      get GPS string location data
        gpsText = displayInfo();

        //        check GPS count
        Serial.print("GPS count : ");
        Serial.println(gpsCounter);

        if (gpsCounter == gpsttlCounter) {

          //          turn on the led , to know data write to SD card
          digitalWrite(led, HIGH);

          //        open the file on SD card for writing/storing the location data

          // Note: if gpslog.csv not found, then, it creates the file, if found then, it appends the file
          File dataFile = SD.open("gpslog.csv", FILE_WRITE);

          if (dataFile) {

            //            if the file is found then, write and close it
            dataFile.println(gpsText);
            dataFile.close();

            //            print the complete data which is written in the file just to know
            Serial.println(gpsText);
          }

          //           file file is not opened then, print an error message
          else {
            Serial.println("error for opening datalog.txt file ");

          }
        }
        //        increment the GPS counter
        gpsCounter = gpsCounter + 1;
//        if gpsCounter is greater than limit value, then reset it
        if (gpsCounter > gpsttlCounter) {
          gpsCounter = 0;
        }
      }
    }
  }
}

// function that stores latitude, longitude, full date, time

String displayInfo() {

  //  variable to hold data
  String gpsData = "";

  //  get latitude and longitude i.e 54.343654,78.469302
  if (gps.location.isValid()) {

    //    Note: 6 means it takes upto 6 decimal point values

    gpsData += String(gps.location.lat(), 6);
    gpsData += (",");
    gpsData += String(gps.location.lng(), 6);
    gpsData += (",");
  }
  else {
    return "0";
  }

  //  get full date i.e 2022-04-14

  if (gps.date.isValid()) {
    gpsData += String(gps.date.year());
    gpsData += ("-");

    if (gps.date.month() < 10 ) {
      gpsData += ("0");
    }
    gpsData += String(gps.date.month());
    gpsData += ("-");

    if (gps.date.day() < 10) {
      gpsData += ("0");
    }

    gpsData += String(gps.date.day());

  }
  else {
    return "0";
  }

  // space between date and time

  gpsData += (" ");

  //  get time i.e 09:34:54

  if (gps.time.isValid()) {

    if (gps.time.hour() < 10) gpsData += ("0");

    gpsData += String(gps.time.hour());
    gpsData += (":");

    if (gps.time.minute() < 10) gpsData += ("0");

    gpsData += String(gps.time.minute());
    gpsData += (":");


    if (gps.time.second() < 10) gpsData += ("0");

    gpsData += String(gps.time.second());


  }

  else {
    return "0";
  }

  //  now, return the complete gps location data
  return gpsData;

}
