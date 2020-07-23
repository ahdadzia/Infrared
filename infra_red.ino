
#define BLYNK_PRINT Serial 

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "NOHnvrPJPSq6pH-PmSIT13jpbAxZAunD";
char ssid[] = "MBAHMUKIPER";
char pass[] = "ahhayas20";

WidgetLED led(V1);

int sensor = D0;

void setup() {
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);


  pinMode(sensor, INPUT);


  while(Blynk.connected() == false){
    Serial.println("Gagal nyambung");
  }

}

void loop() {

  int sensorval = digitalRead(sensor);


  Serial.println(sensorval);
  delay(1000);


  if(sensorval == 1){
    led.on();
  }

  if(sensorval == 0){
    led.off();
  }

  Blynk.run();

}
