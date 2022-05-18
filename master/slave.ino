//Variables y Librerias 
#include <Wire.h>
int sensor = A0;
int x = 0;
void setup()
{
  Serial.begin(9600);
  //Inicia Wire
  Wire.begin();
  pinMode(sensor, INPUT);
}

void loop()
{
  //Inicia Transmision de datos
  Wire.beginTransmission(1);
  //Lee lo que detecta el sensor
  x = analogRead(sensor);
  //Manda el dato x
  Wire.write(x);
  //Termina trasmision
  Wire.endTransmission();
  //Esto se repite cada 1s
  delay(1000);
}
