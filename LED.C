/* pin D7 collegato al pin digitale 2 
 * pin R/W collegato al GND 
 * pin 1 e pin 4 collegati a GND 
 * pin 2 collegato a +Vcc 
 * centrale del potenziometro/trimmer da 10 KOhm collegato al pin 3 del'LCD 
 * pin SX potenziometro/trimmer collegato a +Vcc 
 * pin DX potenziometro/trimmer collegato a GND 
 * i pin SX e DX del potenziometro/trimmer possono essere interscambiati 
*/  
 
  
/* 
   Viene creata l'istanza dell'oggetto LiquidCrystal chiamata lcd in cui 
   sono indicati i pin dell'LCD collegati alle uscite digitali di Arduino 
*/  

#define joyX A5
#define joyY A4
#define joyB 13
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
int xvalue, yvalue, frow = 0, bvalue;
bool fmain = true, ftemperature = false;
  
void setup() {  
  //impostiamo il numero di colonne ed il numero di righe di lcd  
  lcd.begin(16, 2);  
   
  Serial.begin(9600);
}  

  
void loop() {  

  xvalue = analogRead(joyX);
  yvalue = analogRead(joyY);
  bvalue = digitalRead(joyB);

  // posiziona il cursore in colonna 0 e linea 1  
  // (nota: la linea 1 e la seconda linea, poichè si conta incominciando da 0):  
  lcd.setCursor(0, frow);

  if (fmain) {
    lcd.print("Set time        ");
  } 
  else if (ftemperature){
    lcd.print("Set temperature"); 
  }
  if (xvalue > 990) {
    fmain = false;
    ftemperature = true;
  }
  else if (xvalue < 40) {
    fmain = true;
    ftemperature = false;
  }

  if (bvalue) {
    if (frow == 1) {frow = 0;}
    else if (frow == 0) {frow = 1;}
    lcd.setCursor(0,frow);
  }

  Serial.print(bvalue);
  Serial.print("\n");
  //delay(1000);
  
  
  
  
  
  // stampa il numero di secondi dall'ultimo reset  
  //lcd.print(millis()/1000);  
}  