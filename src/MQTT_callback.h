// ===============================================
// Функция обработки MQTT сообщений
void MQTT_callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("[MQTT] Сообщение получено [");
    Serial.print(topic);
    Serial.print("]: ");

    String message = "";
    for (unsigned int i = 0; i < length; i++)
        message += (char)payload[i];
    message.trim();
    Serial.println(message);

    if (String(topic) == STRIP_POWER_TOPIC)
    {
        if (message == "0")
        {
            for (int i = stripBrightness; i > 0; i--)
            {
                FastLED.setBrightness(i);
                FastLED.show();
                delay(10);
            }
            setStripPower(false);
            Serial.println("[STRIP] Лента выключена");
        }
        else if (message == "1")
        {
            FastLED.setBrightness(0);
            setStripPower(true);
            for (int i = 0; i < stripBrightness; i++)
            {
                FastLED.setBrightness(i);
                FastLED.show();
                updateStrip();
                delay(10);
            }
            Serial.println("[STRIP] Лента включена");
        }
    }

    else if (String(topic) == STRIP_BRIGHTNESS_TOPIC)
    {
        int brightnessPercent = message.toInt();
        if (brightnessPercent >= 0 && brightnessPercent <= 100)
        {
            setStripBrightness(brightnessPercent);
            Serial.printf("[STRIP] Яркость установлена: %d%%\n", brightnessPercent);
        }
    }

    else if (String(topic) == STRIP_MODE_TOPIC)
    {
        if (message == "RAINBOW")
        {
            mode = stripMode::RAINBOW;
        }
        else if (message == "CAMPFIRE")
        {
            mode = stripMode::CAMPFIRE;
        }
        else if (message == "DISCO")
        {
            mode = stripMode::DISCO;
        }
        else if (message == "COLOR")
        {
            mode = stripMode::COLOR;
        }
    }

    else if (String(topic) == STRIP_SPEED)
    {
        if (message == "low")
        {
            discoModeDelay = 5000;
        }
        else if (message == "medium")
        {
            discoModeDelay = 2500;
        }
        else if (message == "high")
        {
            discoModeDelay = 1000;
        }
    }

    else if (String(topic) == STRIP_COLOR_RGB)
    {
        // Ожидаем формат: "255,128,0"
        int r = 0, g = 0, b = 0;
        int firstComma = message.indexOf(',');
        int secondComma = message.indexOf(',', firstComma + 1);

        if (firstComma != -1 && secondComma != -1)
        {
            r = message.substring(0, firstComma).toInt();
            g = message.substring(firstComma + 1, secondComma).toInt();
            b = message.substring(secondComma + 1).toInt();

            // Ограничиваем значения 0-255
            r = constrain(r, 0, 255);
            g = constrain(g, 0, 255);
            b = constrain(b, 0, 255);

            stripColor = CRGB(r, g, b);
            mode = stripMode::COLOR;

            Serial.printf("[STRIP] Цвет установлен: R=%d G=%d B=%d\n", r, g, b);
        }
        else
        {
            Serial.println("[STRIP] Ошибка: неверный формат цвета. Ожидается R,G,B");
        }
    }

    else if (String(topic) == RESTART_TOPIC)
    {
        if (message == "1")
        {
            Serial.println("[OTA] Перезагрузка по команде");
            ESP.restart();
        }
    }

    else
    {
        Serial.println("[MQTT] Неизвестная команда: " + message);
        client.publish(TOPIC_TO_PUBLISH, "[ERROR] Неизвестная команда");
    }

    String answerMessage = ": { " + String(topic) + " " + message + " }";
    client.publish(TOPIC_TO_PUBLISH, answerMessage.c_str());
}