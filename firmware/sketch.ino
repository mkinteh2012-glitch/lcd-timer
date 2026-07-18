#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
int min = 10;
int sec = 15;
int time = 0;
bool running = true ;
unsigned long previousMillis = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
// here we are telling the computer what the buttons are and rows anc cols

const byte ROWS = 4;
const byte COLS = 4 ;
char hexaKeys [ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


void timecalulate (){
    time = (min*60) + sec;
}
void setup(){
    Serial.begin(9600);
    timecalulate();
    lcd.init();
    lcd.backlight();   
    }


void loop(){
    char customKey = customKeypad.getKey();
    unsigned long currentMillis = millis(); 
    if (running && (currentMillis - previousMillis >= 1000)){
        previousMillis = currentMillis;
        time = time - 1 ;
        lcd.setCursor(0, 1);   
        lcd.print("    ");       
        lcd.setCursor(0, 1);     
        lcd.print(time); 
    }       
    if (customKey){
        Serial.print("Key Pressed: ");
        Serial.println(customKey);
        
        if (customKey == 'A'){
            time = time + 10 ;
            lcd.setCursor(0, 1);   
            lcd.print("    ");       
            lcd.setCursor(0, 1);     
            lcd.print(time); 

        }

    }

}
