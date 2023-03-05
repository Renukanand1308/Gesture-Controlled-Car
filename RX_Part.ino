#include <VirtualWire.h>
#include <AFMotor.h>

int ledPin = 9;
int buzzPin = 10;
int rxPin = 6;

AF_DCMotor m1(1);
AF_DCMotor m2(4);

int dt = 0; 

void setup()
{
  vw_set_rx_pin(rxPin);
  vw_setup(2000);
  m1.setSpeed(255);
  m2.setSpeed(255);
  pinMode(ledPin,OUTPUT);
  pinMode(buzzPin,OUTPUT);
  vw_rx_start();
  Serial.begin(9600);
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if(vw_get_message(buf, &buflen))
  {
    if(buf[0] == 'f')
    {
      m1.run(FORWARD);
      m2.run(FORWARD);     
      Serial.println("FORWARD");      
    }

    else if(buf[0] == 'b')
    {
      m1.run(BACKWARD);
      m2.run(BACKWARD);
      Serial.println("BACKWARD");
    }

    else if(buf[0] == 'r')
    {
      m2.run(BACKWARD);
      m1.run(FORWARD);
      Serial.println("RIGHT");
    }

    else if(buf[0] == 'l')
    {
      m2.run(FORWARD);
      m1.run(BACKWARD);
      Serial.println("LEFT");
    }

    else if(buf[0] == 'w')
    {
      m2.run(RELEASE);
      m1.run(FORWARD);
      Serial.println("FORWARD RIGHT");
    }

    else if(buf[0] == 'x')
    {
      m2.run(FORWARD);
      m1.run(RELEASE);
      Serial.println("FORWARD LEFT");
    }

    else if(buf[0] == 'y')
    {
      m2.run(RELEASE);
      m1.run(BACKWARD);
      Serial.println("BACKWARD RIGHT");
    }

    else if(buf[0] == 'z')
    {
      m2.run(BACKWARD);
      m1.run(RELEASE);
      Serial.println("LEFT");
    }

   else if(buf[0] == 's')
    {
      m1.run(RELEASE);
      m2.run(RELEASE);
      Serial.println("STOP");
    }

    else if(buf[0] == 'h')
    {
      digitalWrite(buzzPin,HIGH);
      Serial.println("SOUND");
    }

    else if(buf[0] == 'c')
    {
      digitalWrite(buzzPin,LOW);     
    }

    if(buf[0]=='a')
    {  
      digitalWrite(ledPin,HIGH);
      Serial.println("LIGHTS");      
    }  
    else if(buf[0]=='k')
    {
      digitalWrite(ledPin,LOW);
      Serial.println("LIGHTS OFF");
    }
  }                                     
  
   
}

 
