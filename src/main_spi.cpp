#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <SPI.h>

namespace {
constexpr uint8_t BME280_SPI_CS_PIN = 10;
constexpr uint8_t BME280_SPI_MOSI_PIN = 11;
constexpr uint8_t BME280_SPI_MISO_PIN = 12;
constexpr uint8_t BME280_SPI_SCK_PIN = 13;
constexpr float SEA_LEVEL_PRESSURE_HPA = 1013.25f;

Adafruit_BME280 bme(BME280_SPI_CS_PIN, BME280_SPI_MOSI_PIN, BME280_SPI_MISO_PIN,
                   BME280_SPI_SCK_PIN);

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

  Serial.println("Starting BME280 SPI sensor test...");

  if (!bme.begin()) {
    Serial.println("No BME280 sensor found. Check SPI wiring and CS pin.");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("BME280 connected over SPI.");
}

void loop() {
  printSensorReadings();
  delay(2000);
}
