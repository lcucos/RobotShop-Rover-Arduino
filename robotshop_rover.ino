#include <stdarg.h>

// Code to control RobotShop-Rover
// 

int E1 = 6; //M1 Speed Control
int E2 = 5; //M2 Speed Control
int M1 = 8; //M1 Direction Control
int M2 = 7; //M2 Direction Control

void p(char *fmt, ... ){
    char tmp[128]; // resulting string limited to 128 chars
    va_list args;
    va_start (args, fmt );
    vsnprintf(tmp, 128, fmt, args);
    va_end (args);
    Serial.print(tmp);
}

void setup(void)
{
    int i;
    for(i=5;i<=8;i++){
      pinMode(i, OUTPUT);
    }
    Serial.begin(9600);
}

void loop(void)
{
    while (Serial.available() < 1) {} // Wait until a character is received
    char val = Serial.read();
    int leftspeed = 255; //255 is maximum speed
    int rightspeed = 200;// adjust for a small difference between wheels speed
    
    switch(val) // Perform an action depending on the command
    {
       case 'I':
          p("%s", "aXsept0"); 
          break;
       case 'w'://Move Forward
          forward (leftspeed,rightspeed);
          break;
       case 's'://Move Backwards
          reverse (leftspeed,rightspeed);
          break;
       case 'a'://Turn Left
          left (leftspeed,rightspeed);
          break;
       case 'd'://Turn Right
          right (leftspeed,rightspeed);
          break;
       default:
          stop();
          break;
    }
}

void stop(void) //Stop
{
   digitalWrite(E1,LOW);
   digitalWrite(E2,LOW);
}

void forward(char a,char b)
{
    analogWrite (E1,a);
    digitalWrite(M1,LOW);
    analogWrite (E2,b);
    digitalWrite(M2,LOW);
}
void reverse (char a,char b)
{
    analogWrite (E1,a);
    digitalWrite(M1,HIGH);
    analogWrite (E2,b);
    digitalWrite(M2,HIGH);
}
void left (char a,char b)
{
    analogWrite (E1,a);
    digitalWrite(M1,HIGH);
    analogWrite (E2,b);
    digitalWrite(M2,LOW);
}
void right (char a,char b)
{
    analogWrite (E1,a);
    digitalWrite(M1,LOW);
    analogWrite (E2,b);
    digitalWrite(M2,HIGH);
}


