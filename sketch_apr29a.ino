int pot = A0;
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
 
void setup(){
Serial.begin(9600);
Serial.println("CLEARDATA");
Serial.println("LABEL, Time, Started Time, Date, Temperature, Humidity");
Serial.println("RESETTIMER");
dht.begin();
}

void loop()
{
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Serial.print("DATA, TIME, TIMER, DATE,");
  
  Serial.print(" ");
  Serial.print(t);
  
  Serial.print(" , ");
  Serial.print(h);
  Serial.println("%");
  
  delay(1000);
}
