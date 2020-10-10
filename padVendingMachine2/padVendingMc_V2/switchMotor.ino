void switchMotor(){
    String brandArray[]={"HQ","ALWAYS","FREESTYLE"};
  String SizeArray[]={"Medium","Large"};
      
  lcd.setCursor(0,1);
  lcd.print("BRAND- ");
  lcd.setCursor(0,2);
  lcd.print("SIZE- ");
    lcd.setCursor(7,1);
  lcd.print(brandArray[brand-1]);
  lcd.setCursor(7,2);
  lcd.print(SizeArray[Size-1]);
  lcd.clear();
  lcd.setCursor(0,2);
  lcd.print("Please Wait");
  delay(2000);
  digitalWrite(motorRelay,LOW);
  motorSwitch();
  lcd.clear();
  lcd.print("Enjoy");
  delay(2000);
  lcd.clear();
  
  
}
void motorSwitch(){
  bool notPassed=true;
  while(notPassed){
    int x=digitalRead(padPass);
    delay(50);
    if(x==1){
       digitalWrite(motorRelay,HIGH);
       notPassed=false;
    }
  }
}
