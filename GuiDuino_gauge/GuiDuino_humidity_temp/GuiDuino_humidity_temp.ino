#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  dht.begin(); 
  Serial.begin(9600); // Initialisation de la liaison série
  Serial.flush(); // vidé le buffer USB
  
}

void loop()
{
  delay(2000);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
                                           
  Serial.print(h); // l'envoi de la donnée
  Serial.print(",");
  Serial.println(t); 
  
  Serial.flush(); // vidé le buffer USB
}

