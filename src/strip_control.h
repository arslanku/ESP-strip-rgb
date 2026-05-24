// ===============================================
// Функция управления питанием ленты
void setStripPower(bool power)
{
    stripPower = power;
    if (!stripPower)
    {
        FastLED.clear();
        FastLED.show();
        FastLED.clear();
        FastLED.show();
    }
}

// ===============================================
// Функция установки яркости
void setStripBrightness(uint8_t brightnessPercent)
{
    stripBrightness = map(brightnessPercent, 0, 100, 0, 255);
    FastLED.setBrightness(stripBrightness);

    if (stripPower)
    {
        FastLED.show();
    }
}

// ===============================================
// Вспомогательная функция для пульсирующей яркости на основе времени
uint8_t pulsatingBrightness(uint16_t speed = 5, uint8_t minBright = 180, uint8_t maxBright = 255)
{
    uint16_t phase = (millis() / speed) % 256; // значение от 0 до 255
    uint8_t sinVal = sin8(phase);              // 0..255 по синусу
    return map(sinVal, 0, 255, minBright, maxBright);
}

// ===============================================
// Функция обновления состояния ленты
void updateStrip()
{
    if (!stripPower)
        return;

    switch (mode)
    {
    // Эффект РАДУГИ
    case stripMode::RAINBOW:
    {
        static uint8_t raibowHue = 0;
        static uint64_t rainbowTimer = 0;
        if (millis() - rainbowTimer >= 30)
        {
            rainbowTimer = millis();
            raibowHue++;
        }
        for (int i = 0; i < NUM_LEDS; i++)
        {
            leds[i] = CHSV(raibowHue + (i * 255 / NUM_LEDS), 255, 255);
        }
        break;
    }

    // Эффект КОСТРА
    case stripMode::CAMPFIRE:
    {
        for (int i = 0; i < NUM_LEDS; i++)
        {
            uint8_t baseHue = 16 + (i * 3) % 32;
            int8_t hueVar = (random8(10) - 8);
            uint8_t finalHue = baseHue + hueVar;
            uint8_t bright = 180 + random8(76);
            leds[i] = CHSV(finalHue, 255, bright);
        }
        break;
    }

    // ЦВЕТ
    case stripMode::COLOR:
    {
        fill_solid(leds, NUM_LEDS, stripColor);
        break;
    }

    // Продвинутая дискотека с автоматической сменой эффектов
    case stripMode::DISCO:
    {
        static uint8_t discoHue;
        static uint8_t bright;
        static float k;

        switch (discoSpeed)
        {
        case discoModeDelay::SLOW:
            k = 0.1;
            break;
        case discoModeDelay::MEDIUM:
            k = 0.3;
            break;
        case discoModeDelay::FAST:
            k = 0.5;
            break;
        }

        bright = map(sin8(k * millis()), 0, 255, 40, 255);
        fill_solid(leds, NUM_LEDS, CHSV(discoHue, 255, bright));
        discoHue++;
        break;
    }
    }
    FastLED.show();
}

// ===============================================
// Функция подтверждения подключения контроллера
void connectSuccess()
{
    FastLED.clear();
    FastLED.show();
    delay(250);
    for (int i = 0; i < 3; i++)
    {
        fill_solid(leds, NUM_LEDS, CRGB::Green);
        FastLED.show();
        delay(250);

        FastLED.clear();
        FastLED.show();
        delay(250);
    }
}