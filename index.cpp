#include <WiFi.h>
#include <PubSubClient.h>

#define LDR_PIN 34  
#define DHT_PIN 27   
#define LED1_PIN 25  
#define LED2_PIN 26  


const char* ssid = "SEU_SSID"; 
const char* password = "SUA_SENHA"; 


const char* mqtt_server = "BROKER_MQTT";
const char* ldr_topic = "painel/ldr";
const char* temp_topic = "painel/temperatura"; 
const char* hum_topic = "painel/umidade";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  pinMode(LDR_PIN, INPUT);
  pinMode(DHT_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  
  setup_wifi();

  
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect_mqtt();
  }
  client.loop();

  
  int ldrValue = analogRead(LDR_PIN);
  Serial.print("Luminosidade recebida pelo painel solar: ");
  Serial.println(ldrValue);

  
  client.publish(ldr_topic, String(ldrValue).c_str());

  
  float temperature = 0, humidity = 0;
  if (readDHT22(DHT_PIN, &temperature, &humidity)) {
    Serial.print("Temperatura recebida pelo painel solar: ");
    Serial.println(temperature);
    Serial.print("Umidade do ar em (%): ");
    Serial.println(humidity);

    
    client.publish(temp_topic, String(temperature).c_str());
    client.publish(hum_topic, String(humidity).c_str());
  } else {
    Serial.println("Erro ao receber temperatura/umidade no painel solar!");
  }

  
  if (ldrValue < 1000) {
    digitalWrite(LED1_PIN, HIGH);
  } else {
    digitalWrite(LED1_PIN, LOW);
  }

  if (temperature > 30.0) {
    digitalWrite(LED2_PIN, HIGH); 
  } else {
    digitalWrite(LED2_PIN, LOW);
  }

  delay(2000);
}

void setup_wifi() {
  delay(10);
  Serial.println("Conectando ao Wi-Fi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado.");
}

void reconnect_mqtt() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado!");
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

bool readDHT22(int pin, float *temperature, float *humidity) {}#include <WiFi.h>
#include <PubSubClient.h>

