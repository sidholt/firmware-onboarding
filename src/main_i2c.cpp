#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <Wire.h>

namespace {
constexpr uint8_t BME280_I2C_ADDRESS = 0x76;
constexpr float SEA_LEVEL_PRESSURE_HPA = 1013.25f;

Adafruit_BME280 bme;

void printSensorReadings() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" C");

  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEA_LEVEL_PRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();
}
}  // namespace

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Starting BME280 I2C sensor test...");

  if (!bme.begin(BME280_I2C_ADDRESS, &Wire)) {
    Serial.println("No BME280 sensor found. Check wiring and I2C address.");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("BME280 connected over I2C.");
}

void loop() {
  printSensorReadings();
  delay(2000);
}
