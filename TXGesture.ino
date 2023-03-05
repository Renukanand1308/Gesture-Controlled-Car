#include <VirtualWire.h>

int xPin = A0;
int yPin = A1;
int zPin = A2;
int xVal;
int yVal;
int zVal;
int xVal2;
int yVal2;
int zVal2;
int x;
int y;
int z;

char *data;

void setup()
{
  vw_set_tx_pin(12);
  vw_setup(2000);
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
  pinMode(zPin,INPUT);
  Serial.begin(9600);
  xVal2 = analogRead(xPin);
  yVal2 = analogRead(yPin);
  zVal2 = analogRead(zPin);
}

void loop()
{
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  zVal = analogRead(zPin);

  x = xVal - xVal2;
  y = yVal - yVal2;
  z = zVal - zVal2;
  
/*
  Serial.print("X:");
  Serial.println(xVal);
  Serial.print("Y:");
  Serial.println(yVal);
  Serial.print("Z:");
  Serial.println(zVal);
  Serial.println("----------------------------------------");
  delay(750);
*/

  if(y>=10)
  {
    data = "f";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    Serial.println("FORWARD");
  }

  else if(y<= -10)
  {
    data = "b";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    Serial.println("BACKWARD");
  }

  else if(x>=10)
  {
    data = "r";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    Serial.println("RIGHT");    
  }

  else if(x<= -10)
  {
    data = "l";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    Serial.println("LEFT");
  }

  else
  {
    data = "s";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    Serial.println("STOP");    
  }
}