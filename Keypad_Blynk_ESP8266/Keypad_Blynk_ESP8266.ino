#include <ESP8266WiFi.h>
#include <Keypad.h>

const byte ROWS = 2; //two rows
const byte COLS = 2; //two columns
char keys[ROWS][COLS] = {
  {'1','2'},{'4', '5'}
};
byte rowPins[ROWS] = {D0,D1}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {D2,D3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String v_passcode="";

void setup() {
  // Debug console
  pinMode(D5,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key != NO_KEY){
    //Serial.println(key);
    
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
        digitalWrite(D5,HIGH);
        digitalWrite(D7,HIGH);
        delay(3000);
        digitalWrite(D5,LOW);
        digitalWrite(D7,LOW);
      } else if (v_passcode=="11225") {
        Serial.println("Access Granted");
        digitalWrite(D5,HIGH);
        digitalWrite(D7,HIGH);
        delay(3000);
        digitalWrite(D5,LOW);
        digitalWrite(D7,LOW);
      } else {
        Serial.println("Access Denied");
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
