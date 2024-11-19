Detalhamento do Projeto
Objetivo:
Criar um sistema IoT com ESP32 que:

Mede luminosidade com um sensor LDR.
Mede temperatura e umidade com o sensor DHT22.
Publica os valores lidos em um broker MQTT para que possam ser monitorados por outros dispositivos na mesma rede Wi-Fi.
Aciona LEDs com base em condições específicas:
LED 1 acende quando a luminosidade está abaixo de um certo nível.
LED 2 acende quando a temperatura ultrapassa um limite.

Fluxo do Sistema:
O ESP32 se conecta à rede Wi-Fi.
Inicializa a comunicação com o broker MQTT.
Mede os valores do LDR e do DHT22 periodicamente.
Publica os dados em tópicos MQTT específicos.
Controla os LEDs de acordo com os limites definidos.

O ESP32 conecta-se à rede Wi-Fi e publica os valores do LDR, temperatura e umidade em um broker MQTT. 
Os LEDs indicam condições críticas de luminosidade e temperatura, enquanto dispositivos externos podem monitorar os valores em tempo real via MQTT.
