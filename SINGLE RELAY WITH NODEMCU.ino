#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
#define BUTTON  4     // the number of the pushbutton pin
#define relay  5     // the number of the relay pin
int push_button, relay ; //iales to read values 

unsigned long myChannelNumber = 1971314;
const char * myWriteAPIKey = "K6HATN4GK9UKUZ7I";
int buttonState = 0;         // variable for reading the pushbutton status
unsigned long lastTime = 0;
unsigned long timerDelay = 16000;
WiFiClientSecure client;


void setup() 
{ 
  Serial.begin(115200);
  pinMode(led, OUTPUT);   // initialize the LED pin as an output:
  pinMode(BUTTON, INPUT_PULLUP);   // initialize the pushbutton pin as an input:

//connecting esp8266 to wifi   
WiFi.begin("lekeamp","87654321");
 while(WiFistatus()! -WL_CONNECTED)    
{
  serial.println("****")//prints * while the nodemcu is getting connected to the WiFi
  delay(200);
}

 Serial.println("NodeMCU is connected !!");
 ThingSpeak.begin(client);
}

void loop() {
// Initialise as 0
  int button_value = 0, relay_value = 0;

// Check if HIGH
  if (digitalRead(BUTTON) == HIGH) 
    button_value = 1;
  
  if (digitalRead(RELAY) == HIGH) 
    relay_value = 1;

// send to Thingspeak 
  int x = ThingSpeak.writeField(myChannelNumber, 1, button_value, 2, relay_button, myWriteAPIKey);

// check if successfully sent
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  
  delay(16000); //minimum delay for free Thingspeak Account 
 
}
