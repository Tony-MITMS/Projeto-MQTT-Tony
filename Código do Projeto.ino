//Acesso a internet no Arduino

#include <PubSubClient.h>

#include <UIPEthernet.h>
#include <utility/logging.h>
#include <SPI.h>


//Define o endereço MAC que será utilizado
byte mac[] = {0x1C, 0xA9, 0x86, 0x3E, 0x5A, 0xB9};

bool mensagem;
int pino2 = 2;
bool estado_sensor;

//Inicia o cliente Ethernet
EthernetClient client;

PubSubClient mqttClient(client);

void setup() {
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);

    //Inicia o monitor Serial
    Serial.begin(9600);

    mqttClient.setServer("54.210.160.207",1883);

    //Exibe no Monitor Serial as informações sobre o IP do Arduino
    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print("O Gateway do Arduino e: ");
    Serial.println(Ethernet.gatewayIP());

    //Exibe uma linha em branco
    Serial.println("");
    
    pinMode(pino2, INPUT_PULLUP);
    
}

void loop() {
  estado_sensor = digitalRead(pino2);

  if (estado_sensor == 0){
    mqttClient.connect("tonyndefru");
    mensagem = mqttClient.publish("tonyndefru-t","FECHADO!");
    Serial.println(mensagem);
    Serial.println("FECHADO!");
    
  }else {
    mqttClient.connect("tonyndefru");
    mensagem = mqttClient.publish("tonyndefru-t","ABERTA!");
    Serial.println(mensagem);
    Serial.println("ABERTO!");
    }
    mqttClient.loop();    
}
