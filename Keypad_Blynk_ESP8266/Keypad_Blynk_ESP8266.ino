// Chage These Credentials with your Blynk Template credentials
// Chage These Credentials with your Blynk Template credentials 
#define BLYNK_TEMPLATE_ID "TMPL3J4MZf0Uh"
#define BLYNK_TEMPLATE_NAME "Keypad Gmail"
#define BLYNK_AUTH_TOKEN "dvn5w993L8lqapzMD0zxwTZAA5K9lYMZ"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Keypad.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "AnnmonRajiJamesOPPO"; // Change your Wifi/ Hotspot Name
char pass[] = "childsafety"; // Change your Wifi/ Hotspot Password

BlynkTimer timer;

const byte ROWS = 2; //two rows
const byte COLS = 2; //two columns
char keys[ROWS][COLS] = {
  {'1','2'},{'4', '5'}
};
byte rowPins[ROWS] = {D0,D1}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {D2,D3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String v_passcode="";

WidgetLED led(V1);

void setup() //Setup function - only function that is run in deep sleep mode
{
  Serial.begin(9600); //Start the serial output at 9600 baud
  pinMode(D5,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
  
  Blynk.begin(auth, ssid, pass);//Splash screen delay
  delay(2000);
  timer.setInterval(500L, mySensor);
}

void loop() //Loop function
{
  Blynk.run();
  timer.run();
}

void mySensor()
{
   
  char key = keypad.getKey();
  
  if (key != NO_KEY){
    
    v_passcode = v_passcode + key;
    
    if(key=='4') {
      Serial.println("Enter Password");
      v_passcode = "";
    }
    
    if(key=='5') {
      Serial.println("Validate the Password");
      //Serial.println(v_passcode);
        
      if (v_passcode=="12115") {
        Serial.println("Access Granted");
        Blynk.logEvent("Child reached home");
        digitalWrite(D5,HIGH);
        digitalWrite(D7,HIGH);
        delay(3000);
        digitalWrite(D5,LOW);
        digitalWrite(D7,LOW);
      } else if (v_passcode=="11225") {
        Serial.println("Access Granted");
        Blynk.logEvent("An intruder in your house");
        digitalWrite(D5,HIGH);
        digitalWrite(D7,HIGH);
        delay(3000);
        digitalWrite(D5,LOW);
        digitalWrite(D7,LOW);
      } else {
        Serial.println("Access Denied");
        Blynk.logEvent("Someone entered wrong password");
        digitalWrite(D5,HIGH);
        delay(50);
        digitalWrite(D5,LOW);
        delay(50);
        digitalWrite(D5,HIGH);
        delay(50);
        digitalWrite(D5,LOW);
        delay(100);
        digitalWrite(D5,HIGH);
        delay(50);
        digitalWrite(D5,LOW);
        delay(50);
        digitalWrite(D5,HIGH);
        delay(50);
        digitalWrite(D5,LOW);
        digitalWrite(D8,HIGH);
        delay(2000);
        digitalWrite(D8,LOW);
      }      
    }        
  }
}
