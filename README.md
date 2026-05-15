#  Vinheria Agnello — Monitor de Luminosidade

**Checkpoint 01 — Edge Computing & Computer Systems**
FIAP — Engenharia de Software | 2026 |
Professor Lucas D. Augusto
---

## O que é esse projeto?

Sistema feito com Arduino que monitora a luminosidade do ambiente onde os vinhos são armazenados. Dependendo da quantidade de luz, o sistema acende um LED colorido e dispara um apito como alerta.

| Luminosidade | LED | Buzzer |
|---|---|---|
| Baixa (ambiente escuro) | 🟢 Verde | Silencioso |
| Média | 🟡 Amarelo | Silencioso |
| Alta (muito claro) | 🔴 Vermelho | Apita 3 segundos |

---

## Componentes utilizados

- 1x Arduino Uno
- 1x Protoboard
- 1x LDR
- 1x Resistor 10kΩ
- 1x LED Verde, 1x LED Amarelo, 1x LED Vermelho
- 3x Resistores 220Ω (um pra cada LED)
- 1x Buzzer
- Jumpers

---

## Como montar

O LDR é ligado em série com o resistor de 10kΩ entre o 5V e o GND. O ponto do meio vai no pino **A0**.

```
5V → [LDR] → A0 → [10kΩ] → GND
```

| Componente | Pino Arduino |
|---|---|
| LDR | A0 |
| LED Verde | D10 |
| LED Amarelo | D9 |
| LED Vermelho | D8 |
| Buzzer | D7 |

Cada LED precisa de um resistor de 220Ω em série para não queimar.

---

## Código

```cpp
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

delay(500); // pausa entre leituras

}

  

```

---

## Como rodar

1. Abra a **Arduino IDE**
2. Cole o código acima
3. Conecte o Arduino via USB
4. Clique em **Carregar**
5. Abra o **Monitor Serial** (9600 baud) para ver os valores do LDR em tempo real

Para simular, use o [Tinkercad]([[https://www.tinkercad.com](https://www.tinkercad.com/things/2AuozeV0KPZ-fantabulous-snaget/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=c3-_csvtSR4COAFHN_xsA7Tj8xsvylrk27r1EDvhVSE)])
---

## Integrantes

| Nome | RM |
|---|---|
| Eduardo Felix Frois Silva | 574103 |
| Gabriel Henrique Ongarelli Reis | 572636 |
| Matheus de Amorim Brito | 572435 |
| Thiago Gomes Nascimento | 569436 |
