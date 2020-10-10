void chooseBrand(){
  lcd.clear();
  lcd.setCursor(0,0);
    lcd.print("  CHOOSE BRAND");
  char msg1[]="1. HQ";
  char msg2[]="2. ALWAYS";
  char msg3[]="3. FREESTYLE";
  writer(1,0,0,0,100,msg1,msg2,msg3);
  bool brandNotSelected= true;
  while(brandNotSelected){
    lcd.setCursor(14,3);
    lcd.blink();
    key= keypad.getKey();
      switch(key){
        case '1': case '2': case'3':
        lcd.noBlink();
        lcd.print(key);
        brand=key-'0';
        break;

        case '#':{
        brandNotSelected=false;
        lcd.noBlink();
        lcd.clear();
        if(brand==0){
          lcd.clear();
          lcd.setCursor(0,2);
          lcd.print("Can Not Be Empty");
          delay(1000);
          chooseBrand();
        }
        else{
          delay(1000);
          chooseSize();

        }
      }break;
       case '*':{
        lcd.noBlink();
        lcd.clear();
        lcd.setCursor(4,2);
        lcd.print("Cancelled");
          delay(1000);
        lcd.clear();
        chooseBrand();
      }break;
      }

    
  }
  
}
