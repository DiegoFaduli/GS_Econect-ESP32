##Detalhamento do Projeto
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
Sensores como o LDR (sensor de luminosidade) e o DHT22 (sensor de temperatura e umidade) desempenham um papel crucial na preservação do meio ambiente e na transição para fontes de energia limpa e renovável. Esses dispositivos, quando integrados a sistemas inteligentes, permitem monitorar e otimizar o uso de recursos naturais, promovendo eficiência energética e sustentabilidade.
No contexto ambiental, sensores como o DHT22 ajudam a coletar dados precisos sobre temperatura e umidade, informações essenciais para estudar o impacto das mudanças climáticas. Esses dados podem ser utilizados para monitorar florestas, identificar condições que favoreçam incêndios ou até mesmo prever fenômenos climáticos extremos. Já o LDR, ao medir os níveis de luminosidade, pode ser usado para monitorar a luz solar disponível em áreas específicas, fornecendo informações que orientam iniciativas como reflorestamento e manejo de vegetação.
No campo das energias limpas, sensores de luminosidade são particularmente valiosos em sistemas fotovoltaicos, auxiliando na orientação de painéis solares para maximizar a captação de luz. O uso inteligente desses sensores permite aumentar a eficiência na geração de energia solar, uma das fontes mais promissoras para reduzir a dependência de combustíveis fósseis. Além disso, ao monitorar a luz ambiente, é possível controlar sistemas de iluminação pública e doméstica, reduzindo o consumo energético desnecessário.
