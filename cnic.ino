#include <DHT.h>
#include <DHT_U.h>
#include <SoftwareSerial.h>
SoftwareSerial bt(8, 9); // RX, TX
#define DHTPIN A0 // Pin A0
#define DHTTYPE DHT22 // Sensor dht22.
DHT dht(DHTPIN, DHTTYPE);

// Variables
float temperatura;
float humedad;

void setup() {
  bt.begin(38400);
  dht.begin();
}

void loop() {
  temperatura = dht.readTemperature();  // Lee y almacena la temperatura del sensor DHT22
  humedad = dht.readHumidity();        // Lee y almacena la humedad del sensor DHT22
  
  bt.print(temperatura);
  bt.print(" °C");
  bt.print("|"); // Separador para la lista
  bt.print(humedad);
  bt.print(" %");
  delay(2000);                   // Manda datos cada dos segundos (dht22).
}
