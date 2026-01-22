#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 11
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int Tint;
int aval_soil,soil;
char key = 'b';
int led1 = 7;
int led2 = 8;
int IN1 = 5;
int IN2 = 4;
int IN3 = 2;
int IN4 = 3;

long now1,last1;
long now2,last2;

void setup() 
{
    Serial.begin(9600);
    sensors.begin();  
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    delay(1000);
}
void loop() 
{
      if(Serial.available())
            key = Serial.read();  
      else
            key = 'z';
      //******************************   
      if (key == 'a')
            digitalWrite(led1,HIGH);       
      if (key == 'b')
            digitalWrite(led1,LOW);
      if (key == 'g')
            digitalWrite(led2,HIGH);       
      if (key == 'h')
            digitalWrite(led2,LOW);
      //******************************
      if (key == 'c')
      {
            digitalWrite(IN1,LOW);  
            digitalWrite(IN2,HIGH);     
            delay(3000);
            digitalWrite(IN1,LOW);  
            digitalWrite(IN2,LOW);
      }    
      if (key == 'd')
      {
            digitalWrite(IN1,HIGH);  
            digitalWrite(IN2,LOW);     
            delay(3000);
            digitalWrite(IN1,LOW);  
            digitalWrite(IN2,LOW);
      } 
      if (key == 'e')
      {
            digitalWrite(IN3,LOW);  
            digitalWrite(IN4,HIGH);     
            delay(3000);
            digitalWrite(IN3,LOW);  
            digitalWrite(IN4,LOW);
      }    
      if (key == 'f')
      {
            digitalWrite(IN3,HIGH);  
            digitalWrite(IN4,LOW);     
            delay(3000);
            digitalWrite(IN3,LOW);  
            digitalWrite(IN4,LOW);
      } 
      //******************************
      now1 = millis();
      if((now1-last1) > 2500)
      {
        sensors.requestTemperatures(); 
        Tint = sensors.getTempCByIndex(0);
        if ((Tint > 0) && (Tint < 50))
        {
              Serial.print("tp");
              Serial.println(Tint);
        }
        last1=now1;
      }
      //****************************** 
      now2 = millis();
      if((now2-last2) > 1000)
      {
        aval_soil = analogRead(A0);
        soil = map(aval_soil,0,1023,100,0);
        Serial.print("sm");
        Serial.println(soil);
        last2=now2;
      }
      //******************************    
}

