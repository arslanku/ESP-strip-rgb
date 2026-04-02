// ===============================================
// ESP32 table
#if CONTROLLER_TYPE_ESP32_TABLE

#include <WiFi.h>
#include <PubSubClient.h>
#include <FastLED.h>

#define LED_BUILTIN 2
#define LOGGING 1

#define MQTT_CLIENT_NAME "ESP32 (table-1)" // + ...
#define STRIP_POWER_TOPIC "STRIP/table/power"
#define STRIP_BRIGHTNESS_TOPIC "STRIP/table/brightness"
#define STRIP_MODE_TOPIC "STRIP/table/mode"
#define STRIP_SPEED "STRIP/table/speed"
#define STRIP_COLOR_RGB "STRIP/table/colorRGB"
#define TOPIC_TO_PUBLISH "STRIP/table-1/received"
#define RESTART_TOPIC "STRIP/table-1/restart"

#define NUM_LEDS 120
#define DATA_PIN 5
#define LED_TYPE WS2812
#define COLOR_ORDER GRB

#endif

// ===============================================
// ESP8266 table
#if CONTROLLER_TYPE_ESP8266_TABLE

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <FastLED.h>

#define LED_BUILTIN D4
#define LOGGING 1

#define MQTT_CLIENT_NAME "ESP8266 (table-2)" // + ...
#define STRIP_POWER_TOPIC "STRIP/table/power"
#define STRIP_BRIGHTNESS_TOPIC "STRIP/table/brightness"
#define STRIP_MODE_TOPIC "STRIP/table/mode"
#define STRIP_SPEED "STRIP/table/speed"
#define STRIP_COLOR_RGB "STRIP/table/colorRGB"
#define TOPIC_TO_PUBLISH "STRIP/table-2/received"
#define RESTART_TOPIC "STRIP/table-2/restart"

#define NUM_LEDS 120
#define DATA_PIN D1
#define LED_TYPE WS2812
#define COLOR_ORDER GRB

#endif

// ===============================================
// ESP8266 window
#if CONTROLLER_TYPE_ESP8266_WINDOW

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <FastLED.h>

#define LED_BUILTIN D4
#define LOGGING 1

#define MQTT_CLIENT_NAME "ESP8266 (window)" // + ...
#define STRIP_POWER_TOPIC "STRIP/window/power"
#define STRIP_BRIGHTNESS_TOPIC "STRIP/window/brightness"
#define STRIP_MODE_TOPIC "STRIP/window/mode"
#define STRIP_SPEED "STRIP/window/speed"
#define STRIP_COLOR_RGB "STRIP/window/colorRGB"
#define TOPIC_TO_PUBLISH "STRIP/window/received"
#define RESTART_TOPIC "STRIP/window/restart"

#define NUM_LEDS 180
#define DATA_PIN D1
#define LED_TYPE WS2812
#define COLOR_ORDER GRB

#endif

// ===============================================
// ESP8266 bed LEFT
#if CONTROLLER_TYPE_ESP8266_BED_LEFT

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <FastLED.h>

#define LED_BUILTIN D4
#define LOGGING 1

#define MQTT_CLIENT_NAME "ESP8266 (bed-1)" // + ...
#define STRIP_POWER_TOPIC "STRIP/bed/power"
#define STRIP_BRIGHTNESS_TOPIC "STRIP/bed/brightness"
#define STRIP_MODE_TOPIC "STRIP/bed/mode"
#define STRIP_SPEED "STRIP/bed/speed"
#define STRIP_COLOR_RGB "STRIP/bed/colorRGB"
#define TOPIC_TO_PUBLISH "STRIP/bed-1/received"
#define RESTART_TOPIC "STRIP/bed-1/restart"

#define NUM_LEDS 180
#define DATA_PIN D1
#define LED_TYPE WS2812
#define COLOR_ORDER GRB

#endif

// ===============================================
// ESP8266 bed RIGHT
#if CONTROLLER_TYPE_ESP8266_BED_RIGHT

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <FastLED.h>

#define LED_BUILTIN D4
#define LOGGING 1

#define MQTT_CLIENT_NAME "ESP8266 (bed-2)" // + ...
#define STRIP_POWER_TOPIC "STRIP/bed/power"
#define STRIP_BRIGHTNESS_TOPIC "STRIP/bed/brightness"
#define STRIP_MODE_TOPIC "STRIP/bed/mode"
#define STRIP_SPEED "STRIP/bed/speed"
#define STRIP_COLOR_RGB "STRIP/bed/colorRGB"
#define TOPIC_TO_PUBLISH "STRIP/bed-2/received"
#define RESTART_TOPIC "STRIP/bed-2/restart"

#define NUM_LEDS 180
#define DATA_PIN D1
#define LED_TYPE WS2812
#define COLOR_ORDER GRB

#endif

// ===============================================