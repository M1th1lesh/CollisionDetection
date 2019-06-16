#include <ESP8266WiFi.h>;
#include <WebSocketClient.h>;
//#include <>
const char* ssid     = "mithi";
const char* password = "badlapurboy";

char host[] = "192.168.43.31:3000";
char path[] = "/2";

WebSocketClient webSocketClient;
WiFiClient client;

const int trigPin = 2;  //D4
const int echoPin = 0;  //D3
int buzz=10;
long duration;
int distance;
#define LED D0
String data;


void setup() 

{
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(5,OUTPUT); //D1=5
pinMode(14,OUTPUT);
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication

//For WiFi Connection

 WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  delay(5000);
  
  Serial.print(client.connect("192.168.43.31",3000));
  // Connect to the websocket server

  // Handshake with the server
  webSocketClient.path = path;
  webSocketClient.host = host;
  webSocketClient.handshake(client);
  
  
}

void loop() 

{
  // put your main code here, to run repeatedly:
  // Clears the trigPin

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
//
//
//if(distance <=50 && sdistance >20)
//{
//  Serial.println("LED HIGH");
//  Serial.println("");
//  digitalWrite(14,HIGH);
// }
//else
//{
//  Serial.println("LED LOW");
//  Serial.println("");
//  digitalWrite(14,LOW);
//  }
//
// if(distance <20)
// {
//  digitalWrite(5,HIGH);
//  tone(buzz,2000);
////  delay(100);
////  noTone(buzz);
////  delay(100);
//  digitalWrite(5,LOW);
//    }
//   else
//   {
//    digitalWrite(5,LOW);
//    /
//    }

//sent data
 webSocketClient.sendData((String)distance);
    
  webSocketClient.getData(data);
  if (data.length() > 0) 
  {
      //do stuff here
   Serial.print("Server Data");
   Serial.println(data);

  if(data=="1")
  {
  Serial.println("LED HIGH");
  Serial.println("");
  digitalWrite(14,HIGH);
  delay(2000); 
  digitalWrite(14,LOW); 

  }
  if(data=="0")
  {
  Serial.println("LED LOW");
  Serial.println("");
  digitalWrite(14,LOW); 
  }
  if(data=="2")
  {
  digitalWrite(5,HIGH);
  tone(buzz,2000);
//  delay(100);
//  noTone(buzz);
//  delay(100);
  digitalWrite(5,LOW); 
  }
  else
   {
    digitalWrite(5,LOW);
   }
  }
    
      
delay(2000);
}
