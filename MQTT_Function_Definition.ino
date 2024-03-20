// MQTT Functions Definitions
void callback(char* topic, byte* payload, unsigned int length) {
  DEBUG_NNL("Message arrived [");
  DEBUG_NNL(topic);
  DEBUG_NNL("] ");
  for (int i = 0; i < length; i++) {
    DEBUG_NNL((char)payload[i]);
  }
  DEBUG_LN();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(LED, HIGH);
    s = 1;
  } else {
    digitalWrite(LED, LOW);  // Turn the LED off by making the voltage HIGH
    s = 0;
  }
}

// Function to connect ESP32 to WiFi
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  DEBUG_LN();
  DEBUG_NNL("Connecting to ");
  DEBUG_LN(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    DEBUG_NNL(".");
  }

  randomSeed(micros());

  DEBUG_LN("");
  DEBUG_LN("WiFi connected");
  DEBUG_LN("IP address: ");
  DEBUG_LN(WiFi.localIP());
}

// Function to connect ESP32 with MQTT Broker
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    DEBUG_NNL("Attempting MQTT connection...");
    // Connect client with a Client ID to broker with username and password
    if (client.connect("ESP32_Client", mqttUsername, mqttPassword)) {
      DEBUG_LN("connected");
      client.subscribe("led");
    } else {
      DEBUG_NNL("failed, rc=");
      DEBUG_NNL(client.state());
      DEBUG_LN(" Retrying..");
      delay(100);
    }
  }
}