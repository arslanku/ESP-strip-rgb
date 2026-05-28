// ===============================================
// Функция подключения к WiFi
void WIFI_connect()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    static uint64_t timerWiFi = millis();
    while (WiFi.status() != WL_CONNECTED)
    {
        if (millis() - timerWiFi >= 15000)
        {
            ESP.restart();
        }
        delay(500);
        Serial.println("[WIFI] Подключение к Wi-Fi");
    }
}
