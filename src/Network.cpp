#include <Network.h>

#define WIFI_SSID "Redmi Note 10 Pro"
#define WIFI_PASSWORD "malconnect"

#define API_KEY ""
#define FIREBASE_PROJECT_ID ""
#define USER_EMAIL ""
#define USER_PASSWORD ""

void Network::initWiFi() {
    WiFi.disconnect();
    WiFi.onEvent(WiFiEventConnected, SYSTEM_EVENT_STA_CONNECTED);
    WiFi.onEvent(WiFiEventGotIP, SYSTEM_EVENT_STA_GOT_IP);
    WiFi.onEvent(WiFiEventDisconnected, SYSTEM_EVENT_STA_DISCONNECTED);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void WiFiEventConnected(WiFiEvent_t event, WiFiEventInfo_t info) {
    Serial.println("WiFi Connected! Waiting for local IP Address");
}


void WiFiEventGotIP(WiFiEvent_t event, WiFiEventInfo_t info) {
    Serial.print("Local IP Address: ");
    Serial.println(WiFi.localIP());
}


void WiFiEventDisconnected(WiFiEvent_t event, WiFiEventInfo_t info) {
    Serial.println("WiFi Disconnected!");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void Network::firebaseInit() {
    config.api_key = API_KEY;
    Firebase.begin(&config);
}

void Network::firestoreDataUpdate(double volume) {
    if (WiFi.status == WL_CONNECTED && Firebase.ready()) {
        String documentPath = "House/Room1";
        FirebaseJson content;
        content.set("fields/temp")
    }
}