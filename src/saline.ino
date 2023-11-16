#define BLYNK_TEMPLATE_ID "TMPL3R0LDTh35"
#define BLYNK_TEMPLATE_NAME "saline"
#define BLYNK_AUTH_TOKEN "NS8uKUMaawJukOm96Zm9Dp_lhClr0TQD"
 
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
 
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
BlynkTimer timer;

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "M33";
char pass[] = "123456780";

#include <ESP32Servo.h>

Servo myservo1;
#include <HX711.h>

HX711 scale;  // Initializes library functions.
int buzzer = 15;

int calibration_factor = 300000; // Defines calibration factor we'll use for calibrating.
//int calibration_factor = 750000; // Defines calibration factor we'll use for calibrating.


void setup() 
{
  Serial.begin(9600);   // Starts serial communication in 9600 baud rate.
  
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
   
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("WiFi connected");
Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

myservo1.attach(18); 
pinMode(buzzer,OUTPUT);

 scale.begin(32,33);   // Initializes the scaling process.
                         // Used pins are A0 and A1. 
  scale.set_scale();
  scale.tare();          // Resets the scale to 0.
}
 

void loop() 
{
  Blynk.run();
timer.run();

  scale.set_scale(calibration_factor);  // Adjusts the calibration factor.
 float scalval=scale.get_units()*1000;
 Blynk.virtualWrite(V1,scalval);
 
  Serial.print("Reading: ");            // Prints weight readings in .2 decimal kg units.
  Serial.print(scalval);
  Serial.println("gm");
  Serial.print("Calibration factor: "); // Prints calibration factor.
  Serial.println(calibration_factor);
  
 if(scalval>20 && scalval<80)
 {
  Blynk.virtualWrite(V2,"Alert: Saline bottle is low");
  digitalWrite(buzzer,HIGH);
  delay(5000);
  myservo1.write(0);
  digitalWrite(buzzer,LOW);
  }
 else
 {
    myservo1.write(40);
      Blynk.virtualWrite(V2,"Saline normal");
  }
  
  if(Serial.available())  // Calibration process starts if there is a serial connection present.
  {
    char temp = Serial.read();    // Reads users keyboard inputs.
    
    if(temp == '+')      // Increases calibration factor by 10 if '+' key is pressed.
      calibration_factor += 10;
    else if(temp == '-') // Decreases calibration factor by 10 if '-' key is pressed.
      calibration_factor -= 10;
    else if(temp == 'c' || temp == 'C')
      scale.tare();                     // Reset the scale to zero if 'C' key is pressed.
  }

  scale.power_down();    // Puts the scale to sleep mode for 5 seconds.
  delay(5000);
  scale.power_up();
}
