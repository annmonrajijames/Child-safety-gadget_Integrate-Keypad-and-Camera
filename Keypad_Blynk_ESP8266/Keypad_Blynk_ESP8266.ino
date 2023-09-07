#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Keypad.h>

char auth[] = "Enter auth";
char ssid[] = "Enter ssid";
char pass[] = "Enter password";
const byte ROWS = 2; //two row
const byte COLS = 2; //two columns
char keys[ROWS][COLS] = {
  {'1','2'},{'4', '5'}
};
byte rowPins[ROWS] = {D0,D1}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {D2,D3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String v_passcode="";

void setup()
{
  // Debug console
  pinMode(D5,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
   char key = keypad.getKey();
  
  if (key != NO_KEY){
    //Serial.println(key);
    
    v_passcode = v_passcode + key;
    
    if(key=='4')
    {
      Serial.println("Enter Password");
        v_passcode="";
    }
    
    if(key=='5')
    {
      Serial.println("Validate the Password");
        //Serial.println(v_passcode);
        
        if (v_passcode=="12115")
        {
          Serial.println("Access Granted");
          digitalWrite(D5,HIGH);
          digitalWrite(D7,HIGH);
          delay(3000);
          digitalWrite(D5,LOW);
          digitalWrite(D7,LOW);
          Blynk.email(".....@gmail.com, cleopatraviiphilopator2022@gmail.com","Your kid reached home");
        }
        else if (v_passcode=="11225")
        {
          Serial.println("Access Granted");
          digitalWrite(D5,HIGH);
          digitalWrite(D7,HIGH);
          delay(3000);
          digitalWrite(D5,LOW);
          digitalWrite(D7,LOW);
          Blynk.email("......@gmail.com, cleopatraviiphilopator2022@gmail.com","Your kid is in danger at home; \nkid`s location:-\n https://www.google.com/maps/place/12%C2%B051'44.2%22N+77%C2%B026'20.0%22E/@12.862278,77.438877,17z/data=!3m1!4b1!4m6!3m5!1s0!7e2!8m2!3d12.8622777!4d77.4388766"); 
        }
        else
        {
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
          Blynk.email("....., cleopatraviiphilopator2022@gmail.com","Someone entered password wrong");
        }      
    }        
  }
}