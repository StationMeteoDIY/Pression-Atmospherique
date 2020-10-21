// necessite les librairies Adafruit : "Adafruit Unified Sensor" et "Adafruit BME280"
#include <Wire.h>
#include <Adafruit_BME280.h>

// Initialisation du BME pour une utilisation via Bus I2C
Adafruit_BME280 bme;

float temperature, humidity, pressure, altitude;
#define SEALEVELPRESSURE_HPA (1013.25)   // Pression atmosphérique au niveau de la mer.
 
void setup() {
  Serial.begin(115200);
  delay(100);
  
  bme.begin(0x76);   // 0x76 = I2C adresse
}

void loop() {
  getData();
  Serial.print("Température: ");
  Serial.print(temperature, 1);
  Serial.print(" °C");
  Serial.print("\t Pression: ");
  Serial.print(pressure, 2);
  Serial.print(" hPa");
  Serial.print("\t humidité relative : ");
  Serial.print(humidity, 2);
  Serial.print(" %");
  Serial.print("\t Approx. Altitude = ");
  Serial.print(altitude, 0);
  Serial.println(" m");
  delay(1000);
}

void getData() {
  temperature = bme.readTemperature();
  humidity = bme.readHumidity();
  pressure = bme.readPressure() / 100.0F;
  altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
}