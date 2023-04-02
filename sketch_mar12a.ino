#include <SD.h>
#include <SPI.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11

File myFile; // a File Object
String myFileName = "Text.txt"; // The name of the file we will create
int cs = 10;

DHT dht(DHTPIN, DHTTYPE);
void setup()
{
 Serial.begin(9600);
 dht.begin();
 while(!Serial) {
 }
 Serial.println("Initializing SD card...");
 Serial.println();
  
  pinMode(cs, OUTPUT);
  
 // see if the card is present and can be initialized:
 if (!SD.begin(cs)) {
 Serial.println("SD did not initiliaze.");
 while(1);
 }
 Serial.println("SD initialized.\r\n\r\n");

  if (SD.exists("Text.txt")) 
  { // if "file.txt" exists, fill will be deleted
    Serial.println("File \"Text.txt\" "); 
    delay(300);
    if (SD.remove("Text.txt") == true)
    {
      Serial.println("Remove Done");
    } 
    else{
      Serial.println("Cannot remove file");
    }
    delay(600);
  }
 Serial.println("Done Writing");
}
void loop()
{ 
  delay(2000);

  float h = dht.readHumidity();
  
  float t = dht.readTemperature();


  myFile = SD.open(myFileName, FILE_WRITE); // create and open ".txt" to write data
  if (myFile){
    
    myFile.print("Humidity: ");
    myFile.print(h);
    myFile.print("%.");
    myFile.print(" Temperature: ");
    myFile.println(t);
    
    myFile.close(); // close file
    
  } 
  else{
    Serial.println("Can not write number in file.");
  }
  
  delay(1000);
  
 myFile = SD.open(myFileName, FILE_READ); 
  if (myFile) {
    Serial.println("---MyFile.txt---");
    //char character;
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
    Serial.println("Read data in .txt file");
    
  } 
  else{
    Serial.println("Can not read number in file.");
  }
   
  Serial.println();
  Serial.println("Go to file.");
  Serial.println();
  //delay(2000);
  
}
