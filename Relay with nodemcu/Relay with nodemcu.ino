
#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
#define BUTTON  4     // the number of the pushbutton pin
#define relay  5     // the number of the relay pin
int push_button, Relay ; //variables to read data

unsigned long myChannelNumber = 1971314;
const char * myWriteAPIKey = "K6HATN4GK9UKUZ7I";
int buttonState = 0;         // variable for reading the pushbutton status
unsigned long lastTime = 0;
unsigned long timerDelay = 16000;
WiFiClientSecure client;


void setup() 
{ 
  Serial.begin(9600);
  pinMode(relay, OUTPUT);   // initialize the LED pin as an output:
  pinMode(BUTTON, INPUT_PULLUP);   // initialize the pushbutton pin as an input:

//connecting esp8266 to wifi   
WiFi.begin("lekeamp","87654321");
 while( WiFistatus()! -WL_CONNECTED);
{
  Serial.println("****"); //prints * while the nodemcu is getting connected to the WiFi
  delay(200);
}

 Serial.println("NodeMCU is connected !!");
 ThingSpeak.begin(client);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(BUTTON);

  // check if the pushbutton is pressed.
  if (buttonState   == HIGH) 
  {
     digitalWrite(relay, HIGH);   // turn LED on:
  } 
  Serial.println("button is pressed");
  delay(1000);
  else
 {  
  digitalWrite(relay, LOW);  // turn LED off:
  }
   Serial.println("button is released");


  int x = push_button();
 int y = Relay();
  Serial.println("push_button: " + (String) x);
  Serial.println("Relay: " + (String) y);
  ThingSpeak.writeField(myChannelNumber, 1, x, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, y, myWriteAPIKey);
  delay(2000);
}














 