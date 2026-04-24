# 🍷 Vinheria Agnello — Monitor de Luminosidade

**Checkpoint 01 — Edge Computing & Computer Systems**
FIAP — Engenharia de Software | 2026

---

## O que é esse projeto?

Sistema feito com Arduino que monitora a luminosidade do ambiente onde os vinhos são armazenados. Dependendo da quantidade de luz, o sistema acende um LED colorido e dispara um buzzer como alerta.

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
| LED Verde | D9 |
| LED Amarelo | D10 |
| LED Vermelho | D11 |
| Buzzer | D8 |

Cada LED precisa de um resistor de 220Ω em série para não queimar.

---

## Código

```cpp
const int pinLDR      = A0;
const int pinVerde    = 9;
const int pinAmarelo  = 10;
const int pinVermelho = 11;
const int pinBuzzer   = 8;

void setup() {
  pinMode(pinVerde,    OUTPUT);
  pinMode(pinAmarelo,  OUTPUT);
  pinMode(pinVermelho, OUTPUT);
  pinMode(pinBuzzer,   OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinLDR);
  Serial.println(leitura);

  digitalWrite(pinVerde,    LOW);
  digitalWrite(pinAmarelo,  LOW);
  digitalWrite(pinVermelho, LOW);

  if (leitura <= 400) {
    digitalWrite(pinVerde, HIGH);

  } else if (leitura <= 700) {
    digitalWrite(pinAmarelo, HIGH);

  } else {
    digitalWrite(pinVermelho, HIGH);
    tone(pinBuzzer, 1000);
    delay(3000);
    noTone(pinBuzzer);
  }

  delay(500);
}
```

---

## Como rodar

1. Abra a **Arduino IDE**
2. Cole o código acima
3. Conecte o Arduino via USB
4. Clique em **Carregar**
5. Abra o **Monitor Serial** (9600 baud) para ver os valores do LDR em tempo real

Para simular, use o [Tinkercad](https://www.tinkercad.com) ou o [Wokwi](https://wokwi.com) e monte o circuito conforme descrito acima.

---

## Integrantes

| Nome | RM |
|---|---|
|  |  |
|  |  |
|  |  |
|  |  |
|  |  |
