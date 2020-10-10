#include <EEPROM.h>
#include <string.h>
#include <FastIO.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
int padPass =3;
int password=1234;
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3,POSITIVE);
char key;
const byte rows = 4, cols = 3;
char keys[rows][cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[rows] = {A0, A1, A2, A3};
byte colPins[cols] = { 12,11,10};

Keypad keypad =Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

int coinIn=0; // variable that stores the signal when coin is inserted...
#define coin50 4
#define coin100 5
#define motorRelay 4
//#define coin200 6
int counter50=0,counter100=0/*,counter200=0*/;
int amount50=0,amount100=0,/*amount200=0,*/total=0;
int brand=0;
int Size=0;
int brandAdd,sizeAdd;

void setup() {
pinMode(coin50,INPUT);
pinMode(coin100,INPUT);
pinMode(padPass,INPUT);
//pinMode(coin200,INPUT);
pinMode(motorRelay,OUTPUT);
digitalWrite(motorRelay,HIGH);
  
lcd.begin(16,4);
welcome();
delay(2000);
lcd.clear();
}

void loop() {
  customer_User();

}
