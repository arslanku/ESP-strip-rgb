// ===============================================
// Функция подключения к WiFi
void WIFI_connect()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println("[WIFI] Подключение к Wi-Fi");
    }
    Serial.print("[WIFI] Подключен Wi-Fi: ");
    Serial.println(WiFi.SSID());
}