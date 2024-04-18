// Ringlight Code 
#include <esp_now.h>
#include <WiFi.h>

// Packet Structure 
typedef struct {
  uint8_t addresses[20][6];
  uint8_t colors[20][3];
  uint8_t count;
} RCPData;

// Get this device's MAC address
uint8_t thisMAC[6];

void setRGBColor(uint8_t r, uint8_t g, uint8_t b) {
  Serial.print("r:");
  Serial.print(r);
  Serial.print(" g:");
  Serial.print(g);
  Serial.print(" b:");
  Serial.println(b);
  // Set the RGB LED with the given color values
  // (Implementation depends on your LED library)
}

void onDataReceived(const uint8_t *mac, const uint8_t *data, int len) {
  RCPData *myData = (RCPData*)data;

  // Check if this packet contains our MAC address
  for (int i = 0; i < myData->count; i++) {
    if (memcmp(myData->addresses[i], thisMAC, 6) == 0) {
      // This packet is for us, set the LED color
      setRGBColor(myData->colors[i][0], myData->colors[i][1], myData->colors[i][2]);
      break;
    }
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(onDataReceived);

  // Get this device's MAC address
  esp_read_mac(thisMAC, ESP_MAC_WIFI_STA);
  
}

void loop() {
  // Nothing to do here, color updates are handled in the callback
}
