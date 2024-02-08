#include<LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#define sw1 A1
#define sw2 A2
#define sw3 A3
#define sw4 A4
#define sw5 19
#define buzzer 2
int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;
int active=1;
int a=0;
void setup()
{
pinMode(sw1, INPUT);
pinMode(sw2,INPUT);
pinMode(sw3,INPUT);
pinMode(sw4,INPUT);
pinMode(sw5,INPUT);
pinMode(13,OUTPUT);
pinMode(2,OUTPUT);
Serial.begin(9600);
lcd.begin(16, 2);
lcd.setCursor(0,0);
lcd.print(" VOTING MACHINE ");
lcd.setCursor(0,1);
lcd.print("  LCD DISPLAY");
delay(1000);
digitalWrite(sw1, HIGH);
digitalWrite(sw2, HIGH);
digitalWrite(sw3, HIGH);
digitalWrite(sw4, HIGH);
digitalWrite(sw5, HIGH);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("ASK");
lcd.setCursor(4,0);
lcd.print("DP");
lcd.setCursor(8,0);
lcd.print("NOTA");
}
void loop()
{
  lcd.setCursor(0,0);
lcd.print("ASK");
lcd.setCursor(0,1);
lcd.print(vote1);
lcd.setCursor(4,0);
lcd.print("DP");
lcd.setCursor(4,1);
lcd.print(vote2);
lcd.setCursor(8,0);
lcd.print("NOTA");
lcd.setCursor(8,1);
lcd.print(vote3);
Serial.print("VOTER: ");
Serial.println(a);
Serial.print("ASK: ");
Serial.println(vote1);
Serial.print("DP: ");
Serial.println(vote2);
Serial.print("NOTA: "); 
Serial.println(vote3);

Serial.println("__________________________"); 
delay(1000);

/*if(digitalRead(sw4)==0)
{
  active=0;
  Serial.println("ready");
}
else
{
 }
 
while(active=0)
{*/
  if(digitalRead(sw1)==0)
  { 
    digitalWrite(2,HIGH);
    vote1++;
    a++;
    while(digitalRead(sw1)==0);
    digitalWrite(2,LOW);
    active=1;
    delay(1000);
  }

  if(digitalRead(sw2)==0)
   {
    digitalWrite(2,HIGH);
    vote2++;
    a++;
    while(digitalRead(sw2)==0);
    digitalWrite(2,LOW);
    active=1;
    delay(1000);
  }

  if(digitalRead(sw3)==0)
  {
    digitalWrite(2,HIGH);
    vote3++;
    a++;
    while(digitalRead(sw3)==0);
    digitalWrite(2,LOW);
    active=1;
    delay(1000);
  }
//}

/*
if(digitalRead(sw5)==0)
{
  lcd.setCursor(0,0);
  lcd.print("ASK");
  lcd.setCursor(1,1);
  lcd.print(vote1);
  lcd.setCursor(4,0);
  lcd.print("DP");
  lcd.setCursor(5,1);
  lcd.print(vote2);
  lcd.setCursor(8,0);
  lcd.print("NOTA");
  lcd.setCursor(9,1);
}*/

}
