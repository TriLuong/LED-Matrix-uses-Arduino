#include "font.h"
const int DATA = 12; //DS-14
const int CLOCK = 10; //SHCP-11
const int LATCH = 11; //STCP-12
const int pin[]={2,3,4,5,6,7,8,9}; 

char dataBuffer[200];
char dataReceived[200];
char str;
int numLED=5;

char strDefault[]="LED_Matrix";
int lenStr=0;

int index=0;

void setup()
{
  Serial.begin(9600);
  pinMode(DATA,OUTPUT);
  pinMode(CLOCK,OUTPUT);
  pinMode(LATCH,OUTPUT);
  
  for(int i=0; i<8;i++)
  {
    pinMode(pin[i],OUTPUT);
  }
  clearData();
  

}

void loop() 
{
  lenStr=strlen(strDefault);
  getData(strDefault,lenStr);
  scroll(dataBuffer,lenStr);
  
  if(Serial.available())
  {
    label:
      clearData();
      index=0;
      while(Serial.available())
      {
        dataReceived[index++]=Serial.read();
      }
      Serial.println(dataReceived);
      getData(dataReceived,index);   
      while(1)
      {
        if(Serial.available())
          goto label;
        scroll(dataBuffer,index);      
      }
  }  
}

void getData(char data[], int lenStr)
{
  for(int i=0; i<6*lenStr; i++) //Erase dataBuffer
  {
    dataBuffer[i]=0xff;
  }
  
  for (int i=0; i<lenStr;i++)
  {
    for(int j=0;j<6;j++)
    {
      dataBuffer[i*6+j+(numLED)*8]=font[data[i]-32][j]; // Start RUN
    }
  }
}

void scroll(char data[],int lenStr)
{
  for(int i=0;i<6*lenStr+(numLED)*8;i++) //Stop RUN
  {
    for(int hold=0; hold<10; hold++)
    {
      for(int j=0;j<8;j++)
      {
        digitalWrite(LATCH,LOW);
        shiftOut(DATA, CLOCK,MSBFIRST,~data[i+j+24]);
        shiftOut(DATA, CLOCK,MSBFIRST,~data[i+j+16]);
        shiftOut(DATA, CLOCK,MSBFIRST,~data[i+j+8]);
        shiftOut(DATA, CLOCK,MSBFIRST,~data[i+j]); 
        digitalWrite(LATCH,HIGH);
                
        digitalWrite(pin[j],HIGH);
        delay(1);
        digitalWrite(pin[j],LOW);        
      }  
    }   
  }  
}

void clearData()
{
  for(int i=0; i<200; i++)
  {  
    dataReceived[i]=0x00; //Erase DataReceived
    dataBuffer[i]=0xff;
  }  
}


