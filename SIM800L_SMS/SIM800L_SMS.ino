#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2);

const int LED_PIN = 8;
const int LEDPin = 13;

void setup()
{

   pinMode(LED_PIN, OUTPUT); // Set the LED pin as OUTPUT
 pinMode(LEDPin, INPUT); // Set the LED pin as OUTPUT

  Serial.begin(9600);
  
 
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT");
  updateSerial();

  mySerial.println("AT+CMGF=1"); 
  updateSerial();
  mySerial.println("AT+CMGS=\"+254701722066\""); // enter your phone number here (prefix country code)
  updateSerial();
  mySerial.print("Hello how are you doing Samuel speaking"); // enter your message here
  updateSerial();
  mySerial.write(26);
}

void loop()
{
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
