v#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <MHZ19.h>
#include <SoftwareSerial.h>

// ----- Pinos dos componentes -----
#define DHTPIN 2            // Pino de dados do DHT22
#define DHTTYPE DHT22       // Tipo do sensor DHT
#define RELAY_PIN 3         // Pino de controle do relé
#define CO2_RX 8            // RX do MH-Z19 (Arduino recebe)
#define CO2_TX 9            // TX do MH-Z19 (Arduino envia)

// ----- Inicialização dos objetos -----
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);   // Endereço 0x27 comum em módulos I2C
SoftwareSerial co2Serial(CO2_RX, CO2_TX); // RX, TX
MHZ19 co2Sensor(co2Serial);

// ----- Configurações de limite -----
const int CO2_THRESHOLD = 1000; // ppm

void setup() {
  Serial.begin(9600);
  co2Serial.begin(9600);
  dht.begin();
  lcd.begin();
  lcd.backlight();

  co2Sensor.begin(co2Serial);
  co2Sensor.autoCalibration(); // Pode desativar com .autoCalibration(false)

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Garante relé desligado

  lcd.setCursor(0, 0);
  lcd.print("Monitor de Ar");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  int ppmCO2 = co2Sensor.getCO2();

  // Impressão no monitor serial
  Serial.print("Temp: "); Serial.print(temperatura);
  Serial.print(" °C, Umid: "); Serial.print(umidade);
  Serial.print(" %, CO2: "); Serial.print(ppmCO2); Serial.println(" ppm");

  // LCD Linha 1
  lcd.setCursor(0, 0);
  lcd.print("CO2: ");
  lcd.print(ppmCO2);
  lcd.print("ppm  ");

  // LCD Linha 2
  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperatura, 1);
  lcd.print("C H:");
  lcd.print(umidade, 0);
  lcd.print("%");

  // Controle do relé
  if (ppmCO2 > CO2_THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH); // Liga o relé
  } else {
    digitalWrite(RELAY_PIN, LOW);  // Desliga o relé
  }

  delay(2000); // Atualização a cada 2s
}
