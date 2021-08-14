
#include <I_D.h>
//pines banneados temporalmente STRAPPING: 14, 15, 10, 13, 16
void setup()
{
  Serial.begin(9600);
  engine.initializeMotors();
  engine.enableBrake();
}

void loop()
{
  engine.throttleMotor();
  engine.brake();
}



/* CODIGO de luz intermitente
#include <Arduino.h>
#define ledpin 25
#define button 22
#define debounceTime 10
volatile bool bandera = LOW;

void IRAM_ATTR inter()
{
  if (digitalRead(button) == LOW && bandera == LOW)
  {
    bandera = LOW;
  }
  else if (digitalRead(button) == HIGH && bandera == LOW)
  {
    bandera = HIGH;
  }
  else if (digitalRead(button) == HIGH && bandera == HIGH)
  {
    bandera = LOW;
  }
  else if (digitalRead(button) == LOW && bandera == HIGH)
  {
    bandera = HIGH;
  }
}

void blink()
{
  digitalWrite(ledpin, HIGH);
  delay(200);
  digitalWrite(ledpin, LOW);
  delay(200);
}

void setup()
{
  pinMode(button, INPUT);
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(button, inter, RISING);
}

void loop()
{
  
  if (bandera == HIGH)
  {
    blink();
  }
  else
  {
    digitalWrite(ledpin, LOW);
  }
  Serial.print("el boton esta en: ");
  Serial.print(digitalRead(button));
  Serial.print(" la bandera está en: ");
  Serial.println(bandera);
}
*/