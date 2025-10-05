#include  <EEPROM.h>
#include <Wire.h>
#include <TEA5767N.h>
#include <LiquidCrystal_I2C.h>
#define  LED_PIN 3 //pin connected to LED terminal on the LCD

LiquidCrystal_I2C lcd(0x27,  16, 2);

//Constants:
TEA5767N Radio = TEA5767N(); // Using standard I2C  pins A4 and A5

//Variables:
int P1 = 2;
int B2 = 4;
float freq =  87.60;
int address=0;

void setup () {
  //Init
  lcd.init();
  lcd.backlight();
  pinMode(LED_PIN, OUTPUT);
  analogWrite(LED_PIN, 50);  //you can modify the value of LCD LED from 0 to 255 in order to regular the brightness  contrast
  

  lcd.setCursor(0, 0);
  lcd.print(EEPROM.get(address,freq));
  lcd.setCursor(6, 0);
  lcd.print("MHz");
  Radio.selectFrequency(EEPROM.get(address,freq));
  pinMode(P1, INPUT);
  pinMode(B2, INPUT);
}

void loop () {

  
  if (digitalRead(P1)==HIGH) {
    freq+=0.1;
    EEPROM.put(address,  freq);
    Radio.selectFrequency(EEPROM.get(address,freq));
       lcd.setCursor(0,  0);
       lcd.print(EEPROM.get(address,freq));
       lcd.setCursor(6, 0);
       lcd.print("MHz");
      
    }

    else if(digitalRead(B2)==HIGH)  {
       freq-=0.1;
    EEPROM.put(address, freq);
    Radio.selectFrequency(EEPROM.get(address,freq));
       lcd.setCursor(0, 0);
       lcd.print(EEPROM.get(address,freq));
       lcd.setCursor(6,  0);
       lcd.print("MHz");
    }


    }