/*
codigo para limpiar el data sketch
  comenta el codigo depende el ESP que se utilice, 
  deja solo las secciones depende del ESP
*/

#include <Arduino.h>

#if defined(ESP32)
  #include "SPIFFS.h"
  const int ledPin = 33;
  const int conect = 115200;
#elif defined(ESP8266)
  #include <FS.h>
  const int ledPin = LED_BUILTIN;
  const int conect = 74880;
#endif

void setup() {
  Serial.begin(conect);
  pinMode(ledPin, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);
  
  //inicializacion de SPIFFS
  if (!SPIFFS.begin()) { 
    Serial.println("Error al montar SPIFFS"); 
    return; 
  }
  /* seccion para ESP 32-cam 
  else{
    File root = SPIFFS.open("/");
    File file = root.openNextFile();
    while(file){
      Serial.print("Archivo en SPIFFS: ");
      Serial.println(file.name());
      file = root.openNextFile();
    }
    Serial.println("montado: SPIFFS");
  }
  /* fin seccion para ESP 32-cam */

  /* seccion para ESP 8266*/
  Dir dir = SPIFFS.openDir("/"); 
  Serial.print("Archivo en SPIFFS: "); 
  while (dir.next()) {
    Serial.println(dir.fileName()); 
  }
  /*fin seccion para ESP 8266*/
}

void loop() {
  digitalWrite(ledPin, HIGH); 
  delay(2000);  
  digitalWrite(ledPin, LOW); 
  delay(2000);  
}
