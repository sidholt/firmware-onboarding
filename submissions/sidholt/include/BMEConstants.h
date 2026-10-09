#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t I2C_ADDR = 0x76;

    constexpr uint8_t SPI_CS = 10;
    constexpr uint8_t SPI_MOSI = 11;
    constexpr uint8_t SPI_MISO = 12;
    constexpr uint8_t SPI_SCK = 13;

    constexpr float SEA_LEVEL_HPA = 1013.25f;

    constexpr uint8_t LED_PIN = 13;

    constexpr float MIN_TEMP = 15.0f;
    constexpr float MAX_TEMP = 35.0f;
    constexpr unsigned long SLOW_MS = 1000;
    constexpr unsigned long FAST_MS = 100;
}
