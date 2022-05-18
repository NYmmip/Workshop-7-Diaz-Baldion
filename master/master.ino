//Variables y Librerias 
#include <Wire.h>
int sensor = A0;
int led = 7;
int x = 0;
long temp = 0;
void setup()
{
  Serial.begin(9600);
  //Inicia Wire y se usa metodo onReceive para que ejecute 
  //el bloque de codigo cada vez que recibe datos
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  pinMode(7, OUTPUT);
}

void loop()
{
  //Inicia Transmision de datos
  Wire.beginTransmission(1);
  //Validacion de temperatura para el encendido del LED
  if(temp>30){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
}

//Este metodo se ejecuta cada vez que se reciben datos
//Se utiliza para calcular la temperatura apartir de lo que manda el sensor
void receiveEvent(int howMany){
  x = Wire.read();
  temp = ((long)x*5000)/1023;
  temp = temp/10;
  Serial.println(temp);
}
