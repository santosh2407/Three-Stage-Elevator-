
#include <LiquidCrystal.h>
#define pwm1     9
#define pwm2     10
int i=1;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define btn3 6
#define btn2 7
#define btn1 8
boolean buttonState1;
boolean buttonState2;
boolean buttonState3;

void setup() {
 pinMode(pwm1, OUTPUT);
 pinMode(pwm2, OUTPUT);
 lcd.begin(16,2);
 Serial.begin(9600);
 pinMode(btn1,INPUT_PULLUP);
 pinMode(btn2,INPUT_PULLUP);
 pinMode(btn3,INPUT_PULLUP);
 
}

void loop() {
buttonState1 = digitalRead(btn1);
buttonState2 = digitalRead(btn2);
buttonState3 = digitalRead(btn3);  
  digitalWrite(pwm1,LOW);
  digitalWrite(pwm2,LOW);
     
   if(buttonState3 == HIGH){
    while(i<3){  
    i++;
  digitalWrite(pwm1, LOW);
  digitalWrite(pwm2, HIGH);
 lcd.clear();
      lcd.print("On the way to ");
      lcd.setCursor(0,1);
       lcd.print("floor ");  
 lcd.print(i);
      delay(1000);
      lcd.clear();}
   i=3;
   lcd.clear();
 lcd.print("At Level 3");
  }
 
 
  if(buttonState2==HIGH){
   
    if(i>2){
      while(i>2) {
      i--;
 digitalWrite(pwm1, HIGH);
 digitalWrite(pwm2, LOW);
        lcd.clear();
    lcd.print("On the way to");
        lcd.setCursor(0,1);
        lcd.print("floor ");
        lcd.print(i);
   delay(1000);}
    }
   
    if(i<2){
      while(i<2){
        i++;
    digitalWrite(pwm1, LOW);
  digitalWrite(pwm2, HIGH);
   lcd.clear();
        lcd.print("On the way to");
       lcd.setCursor(0,1);
    lcd.print("floor ");
        lcd.print(i);
        delay(1000);}  
    }    
   
  i=2;lcd.clear();
    lcd.print("At Level 2");
  }

 
  if(buttonState1 == HIGH){
   
  if(i>1){
    while(i>1) {
    i--;
 digitalWrite(pwm1, HIGH);
 digitalWrite(pwm2, LOW);
    lcd.clear();
      lcd.print("On the way to");
     lcd.setCursor(0,1);
    lcd.print("floor ");
      lcd.print(i);
      delay(1000);
      lcd.clear();}
    i=1;    lcd.clear();
  lcd.print("At Level 1");
  }
   
  }
}
