// ===============================================
// Функция обработки MQTT сообщений
void MQTT_callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("[MQTT] Сообщение получено [");
    Serial.print(topic);
    Serial.print("]: ");

    String message = "";
    for (int i = 0; i < length; i++)
        message += (char)payload[i];
    Serial.println(message);

    // Обработка топиков
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

            client.publish("STRIP-status", "1");
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

    else if (topic == STRIP_MODE_TOPIC)
    {
        if (message == "1")
        {
            mode = stripMode::RAINBOW;
        }
        else if (message == "2")
        {
            mode = stripMode::CAMPFIRE;
        }
    }

    else if (String(topic) == RESTART_OTA_TOPIC)
    {
        if (message == "1")
        {
            Serial.println("[OTA] Перезагрузка по команде");
            ESP.restart();
        }
    }

    String answerMessage = ": [ " + String(topic) + " " + message + " ]";
    client.publish(TOPIC_TO_PUBLISH, answerMessage.c_str());
}