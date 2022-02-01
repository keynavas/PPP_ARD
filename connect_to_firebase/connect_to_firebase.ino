#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
 

#define FIREBASE_HOST "firebase host" 
#define FIREBASE_AUTH "tFIREBASE_AUTH_secret" 
#define WIFI_SSID "SSID" 
#define WIFI_PASSWORD "PASSWORD" 

const int RELAY_PIN = 13;
 
void setup() { 
  Serial.begin(9600); 
 
  // connect to wifi. 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
  Serial.print("connecting"); 
  while (WiFi.status() != WL_CONNECTED) { 
    Serial.print("."); 
    delay(500); 
  } 
  Serial.println(); 
  Serial.print("connected: "); 
  Serial.println(WiFi.localIP()); 
  // initialize digital pin as an output.
  pinMode(RELAY_PIN, OUTPUT);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
} 
 
int n = 0; 
 
void loop() { 
  // set value 
  //Firebase.setFloat("number", 42.0); 
  // handle error 
 // if (Firebase.failed()) { 
    //  Serial.print("setting /number failed:"); 
    //  Serial.println(Firebase.error());   
    //  return; 
 // } 
 // delay(1000); 
 
  // remove value 
 // Firebase.remove("number"); 
   
  FirebaseObject object = Firebase.get("/");
  String state = object.get("user/lamp1/state");
  if(state==0){
      digitalWrite(RELAY_PIN, LOW);
  }else if (state==1){
     digitalWrite(RELAY_PIN,HIGH );
  }
  
}
