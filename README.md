# Monitor de Qualidade do Ar com Arduino – CO₂, Temperatura, Umidade e Controle de Exaustor

Este projeto utiliza um Arduino Uno para monitorar a qualidade do ar em ambientes internos, medindo **CO₂**, **temperatura** e **umidade**, e acionando automaticamente um **exaustor** via módulo relé quando o CO₂ ultrapassa um limite configurado.

## Funcionalidades

- Leitura de concentração de CO₂ (sensor MH-Z19)
- Medição de temperatura e umidade (sensor DHT22)
- Exibição das leituras em um display LCD 1602 com interface I2C
- Acionamento automático de exaustor via módulo relé
- Código simples e comentado para fácil personalização

## Componentes Utilizados

- Arduino Uno R3
- Sensor de CO₂ **MH-Z19**
- Sensor de temperatura e umidade **DHT22**
- Display **LCD 1602 com módulo I2C**
- Módulo Relé 1 Canal 5V
- Jumpers e protoboard

## Bibliotecas Necessárias

Instale via Gerenciador de Bibliotecas do Arduino IDE:
- `DHT sensor library` (Adafruit)
- `Adafruit Unified Sensor`
- `LiquidCrystal_I2C`
- `MHZ19` (Jonathan Dempsey)
- `SoftwareSerial` (já incluída na IDE)

## Como Usar

1. Monte o circuito conforme a tabela de conexões.
2. Carregue o código no Arduino via Arduino IDE.
3. Abra o **Serial Monitor** para ver as leituras.
4. Observe o LCD para monitoramento local.
5. O relé será acionado automaticamente quando o CO₂ ultrapassar o limite definido no código (`CO2_THRESHOLD`).
   
## Esquema de Ligação
| Componente        | Pino Arduino |
|------------------|--------------|
| **DHT22**        | DATA → D2, VCC → 5V, GND → GND |
| **MH-Z19**       | TX → D8, RX → D9, VCC → 5V, GND → GND |
| **LCD I2C**      | SDA → A4, SCL → A5, VCC → 5V, GND → GND |
| **Relé 5V**      | IN → D3, VCC → 5V, GND → GND |
