// def dos pinos
const int pinLDR = A0;
const int pinVerde = 10;
const int pinAmarelo = 9;
const int pinVermelho = 8;
const int pinBuzzer = 7;

// def dos limiares
const int LIMIAR_BAIXO = 400; // abaixo disso = escuro = ok
const int LIMIAR_ALTO  = 700; // acima disso = mt claro = problema

void setup() {
  // configura leds e buzzer
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  Serial.begin(9600); // ativa o monitor serial para acompanhamento das leituras
}

void loop() {
  int leitura = analogRead(pinLDR); // le o valor do ldr

  Serial.print("Leitura LDR: ");
  Serial.println(leitura); // imprime no monitor serial

  // apaga todos os leds antes de decidir qual acender
  digitalWrite(pinVerde,    LOW);
  digitalWrite(pinAmarelo,  LOW);
  digitalWrite(pinVermelho, LOW);

  if (leitura <= LIMIAR_BAIXO) {
    // ambiente escuro
    digitalWrite(pinVerde, HIGH);
  } 

  else if ((leitura <= LIMIAR_ALTO) && (leitura > LIMIAR_BAIXO)) {
    // luminosidade moderada
    digitalWrite(pinAmarelo, HIGH);
  } 

  else {
    // luminosidade alta
    digitalWrite(pinVermelho, HIGH);

    tone(pinBuzzer, 1000);   // toca o buzzer em 1000hz
    delay(2000);             // mantem por 2 segundos
    noTone(pinBuzzer);       // para o buzzer

    // verifica novamente
  }
}

  delay(500); // pausa entre leituras
