# Projeto-Seguranca-do-Rack-MQTT
Repositório para o Projeto da Segurança da porta duma Rack de rede.

## Objetivo:

Desenvolver um sistema de alerta sobre a segurança do Rack de equipamentos de rede. [Usando Arduino](https://www.arduino.cc/) Uno e um Sensor Magnético e se conecta com o Módulo Ethernet (ENC28J60) para o monitoramento da porta do RACK de rede, desta forma tendo um retorno remoto do estado da porta que pode ser Aberto ou Fechado. Essa informação é enviada pela internet utilizando o protocolo [MQTT](https://mqtt.org/) (Message Queuing Telemetry Transport) para um outro servidor hospedado na [AWS](https://aws.amazon.com/pt/) (Amazon Web Service) que exibe a mensagem no aplicativo para SmartPhone [MQTT Dash](https://play.google.com/store/apps/details?id=net.routix.mqttdash&hl=pt_BR&gl=US) veja a imagem em anexo:

![TOPOLOGIA](https://github.com/Tony-MITMS/Projeto-Seguranca-do-Rack-MQTT/blob/main/topologia%20do%20projeto.png)

Vamos utilizar neste projeto as seguintes [biblotecas](https://josecintra.com/blog/guia-instalacao-utilizacao-bibliotecas-arduino/):

- [UIPEthernet](https://github.com/UIPEthernet/UIPEthernet)
- [PubsubClient](https://github.com/knolleary/pubsubclient)

## Materiais utilizados para a execução do projeto:

- [Arduino Uno](https://www.arduino.cc/)
- [Sensor Magnético (MC-38)](https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-magnetico-com-fio-para-alarme-mc-38/)
- [Módulo Ethernet (ENC28J60)](https://www.arduino.cc/search?q=M%C3%B3dulo%20Ethernet%20%28ENC28J60%29)
- [Jumpers](https://www.arduino.cc/search?q=jumpers&tab=store)

## Circuito:

![CIRCUITO](https://github.com/Tony-MITMS/Projeto-Seguranca-do-Rack-MQTT/blob/main/Circuito%20do%20projeto.png)

## Autor: Tony Ndefru Frachaha

- [<img alt="LinkedIn" src="https://img.shields.io/badge/linkedin%20-%230077B5.svg?&style=for-the-badge&logo=linkedin&logoColor=white"/>](https://www.linkedin.com/in/tony-ndefru-tony-f-ndefru-b5725b143/)
- [<img alt="Facebook" src="https://img.shields.io/badge/Facebook%20-%231877F2.svg?&style=for-the-badge&logo=Facebook&logoColor=white"/>](https://www.facebook.com/Man-In-The-Mirror-100929294994555)
- [<img alt="Website MITMS" src="https://img.shields.io/badge/Website MITMS-000000?style=for-the-badge&logo=mitms&logoColor=white" />](https://www.maninthemirrors.com/)
- [<img alt="Amazon Books Page" src="https://img.shields.io/badge/Amazon Books Page%20-%23FF9900.svg?&style=for-the-badge&logo=amazon-com&logoColor=white"/>](https://www.amazon.com/Tony-Ndefru-Frachaha/e/B07PJ1DP3D%3Fref=dbs_a_mng_rwt_scns_share)

