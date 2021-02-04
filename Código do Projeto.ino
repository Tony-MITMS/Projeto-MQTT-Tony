//Acesso a internet no Arduino

#include <PubSubClient.h>
#include <UIPEthernet.h>
#include <utility/logging.h>
#include <SPI.h>

//MacAdress 1C-A9-86-3E-5A-B9
//Define o endereço MAC que será utilizado
byte mac[] = {0x1C, 0xA9, 0x86, 0x3E, 0x5A, 0xB9};
bool mensagem; //Para obter as respostas somente duas: 0 ou 1 / False or True
int pino2 =2; //Define o pino como uma variavel para identificação.
bool estado_sensor;


//Inicia o cliente Ethernet
EthernetClient client;
PubSubClient mqttClient(client);

void setup() {

    pinMode (pino2,INPUT_PULLUP); //Define o pino 2 com entrada
         
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);

    //Inicia o monitor Serial
    Serial.begin(9600);

    //Definição de IP e porta TCP do Broker MQTT
    mqttClient.setServer("54.174.235.157",1883);

    //Exibe no Monitor Serial as informações sobre o IP do Arduino
    Serial.print("O IP do Arduino é: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino é: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print("O Gateway do Arduino é: ");
    Serial.println(Ethernet.gatewayIP());

    //Exibe uma linha em branco
    Serial.println("");

}

void loop() {

    estado_sensor = digitalRead(pino2); //O estado do sensor vai ser alterado segundo a leitura feita do pino 2.

Serial.print("O estado do sensor é: ");
Serial.println(estado_sensor);
delay(1000);
 
 mqttClient.connect ("tonyndefru");

//Se o estado do sensor for igual a 0 a variavel vai armazenar uma resposta que vai ser exibido.
if (estado_sensor == 0){
mensagem = mqttClient.publish("Rack-Sala11", "FECHADO!");
Serial.println(mensagem);
delay (500);

}
//Se o estado do sensor for igual a 1 a variavel vai armazenar uma resposta que vai ser exibido.
else {
    mensagem = mqttClient.publish("Rack-Sala11", "ABERTO!");
    Serial.println(mensagem);
    
    mqttClient.loop();

    delay(500);
    }
    
}