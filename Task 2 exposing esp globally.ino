#include<ESP8266WiFi.h>
IPAddress staticIP(192,168,1,254);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,0,0);

void setup() {
Serial.begin(9600);
WiFi.disconnect();
delay(200);
Serial.println( "START");
WiFi.begin("Lekeamp", "87654321");
while (WiFi.status() != WL_CONNECTED) 
{
  delay(500);
  Serial.print("***");
}
Serial.println( "Connected");
Serial.println( "Local ip");
Serial.println(WiFi.localIP());
Serial.println( "gateway");
Serial.println(WiFi.gatewayIP().toString().c_str());
Serial.println( "Your host name");
Serial.println( WiFi.hostname ());
WiFi.config(staticIP, gateway, subnet);
WiFi.hostname( "Lekeamp");
delay(2000);

Serial.println( "New Local IP");
Serial.println(WiFi.localIP());
Serial.println( "new gateway");
Serial.println(WiFi.gatewayIP().toString().c_str());
Serial.println( "Your new host name");
Serial.println( WiFi.hostname ());
}

void loop() {
  // put your main code here, to run repeatedly:

}
