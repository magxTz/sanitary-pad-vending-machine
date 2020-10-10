void chooseSize(){
  char msg1[]="SELECT SIZE";
  char msg2[]="1. Medium ";
  char msg3[]="2. Large";
  writer(0,3,5,5,100,msg1,msg2,msg3);
  bool sizeNotSelected= true;
  while(sizeNotSelected){
    lcd.setCursor(8,3);
    lcd.blink();
    key=keypad.getKey();
    switch(key){
      case '1': case '2':
      lcd.noBlink();
        lcd.print(key);
        Size=key-'0';
        break;
        case '*':
         lcd.clear();
         lcd.noBlink();
         delay(300);
         lcd.setCursor(4,2);
         lcd.print("Cancelled");
         lcd.clear();
         chooseSize();
         break;
    }
    if(key=='#'){
          sizeNotSelected=false;
          lcd.clear();
          lcd.noBlink();
          lcd.setCursor(5,2);
          lcd.print("done");
          delay(2000);
          lcd.clear();
          switchMotor();
    }
  }
}
