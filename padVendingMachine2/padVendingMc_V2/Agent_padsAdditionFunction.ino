void AgentPadsAdd(){
  lcd.setCursor(0,0);
  lcd.print(" ADD PADs STOCK");
  char msg1[]="1. HQ";
  char msg2[]="2. ALWAYS";
  char msg3[]="3. FREESTYLE";
  writer(1,2,2,2,80,msg1,msg2,msg3);
 bool noFeed=true;
 int choice;
 while (noFeed){
  key=keypad.getKey();
  lcd.setCursor(15,3);
  lcd.blink();
  switch(key){
    case '1':
       choice=key-'0';
       lcd.setCursor(15,3);
       lcd.print(choice);
    break;
    case '2':
    choice=key-'0';
    lcd.setCursor(15,3);
    lcd.print(choice);
    break;
    case'3':
    choice=key-'0';
    lcd.setCursor(15,3);
    lcd.print(choice);
    break;
    case '#':
    lcd.noBlink();
    brandAdd=choice;
    noFeed=false;
  }
 
 }
  if(choice>0){
    lcd.noBlink();
    brandAdd=choice;
    lcd.clear();
    padSizeAdd();
    
    
  }
  
}

void padSizeAdd(){
  lcd.setCursor(0,0);
  lcd.print("SELECT SIZE");
  char msg1[]="1. medium";
  char msg2[]="2. large";
  char msg3[]="3. Extra large";
  writer(1,1,1,0,80,msg1,msg2,msg3);
 bool noFeed=true;
 int choice;
 while (noFeed){
  key=keypad.getKey();
  lcd.setCursor(15,3);
  lcd.blink();
  switch(key){
    case '1':
      choice=key-'0';
        lcd.setCursor(15,3);
    lcd.print(choice);
    break;
    case '2':
    choice=key-'0';
    lcd.setCursor(15,3);
    lcd.print(choice);
    break;
    case'3':
    choice=key-'0';
    lcd.print(choice);
    break;
    case'#':
        lcd.noBlink();
      sizeAdd=choice;
      lcd.clear();
      noFeed=false;
    break;
    case '*':
        lcd.noBlink();
    lcd.clear();
     padSizeAdd();
    break;
  }
  if(choice>0){
    lcd.noBlink();
      sizeAdd=choice;
  }
  
  
  }
}
