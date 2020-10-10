
void welcome(){
   lcd.setCursor(3,0);
  lcd.print("WELCOME TO");
  lcd.setCursor(3,1);
  lcd.print("PAD VENDING");
    lcd.setCursor(5,2);
  lcd.print("MACHINE");
}
void customer_User(){
  int choice;
  int posX=0,posY=0;
  lcd.setCursor(5,0);
  lcd.print("WELCOME");
  char msg1[]="Please Select";
  char msg2[]="1. CUSTOMER";
  char msg3[]="2. AGENT";
  writer(1,1,2,2,80,msg1,msg2,msg3);
 bool noFeed=true;
 while(noFeed){
  posX=14,posY=3;
    lcd.setCursor(posX,posY);
  lcd.blink();
  key=keypad.getKey();
  switch(key){
    case NO_KEY:
    break;
    case '1':
     choice=key-'0';
     lcd.setCursor(posX,posY);
     lcd.print(choice);
     break;
    case '2':
     choice=key-'0';
     lcd.setCursor(posX,posY);
     lcd.print(choice);
     break;
     case '*':
     lcd.noBlink();
     lcd.clear();
     customer_User();
     break;
     case '#':
     lcd.noBlink();
     noFeed=false;
  }
  
 }
 lcd.noBlink();
 if(choice==1){
   lcd.clear();
   chooseBrand();
 }
 if(choice==2){
   lcd.clear();
  Agent();
 } 
}
void Agent(){
  int pass=0;
  lcd.setCursor(5,0);
  lcd.print("WELCOME");
  char msg1[]="Insert Password";
  char msg2[]="";
  char msg3[]="";
  writer(1,1,2,2,80,msg1,msg2,msg3);
  int choice;
  bool noFeed=true;
  int  posX=5,posY=2;
  while(noFeed){

    lcd.setCursor(posX,posY);
  lcd.blink();
  key=keypad.getKey();
  switch(key){
    case NO_KEY:
    break;
    case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
    posX++;
     pass=pass*10+(key-'0');
     lcd.setCursor(posX,posY);
     lcd.print("*");
     break;
     case '*':
     lcd.clear();
     lcd.noBlink();
     Agent();
     break;
     case '#':
     lcd.clear();
     lcd.noBlink();
     noFeed=false;
  }
  }
  lcd.noBlink();
  if (pass!=password){
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("Invalid Password");
    delay(1000);
    lcd.clear();
    Agent();
  }else{
    lcd.clear();
    AgentPadsAdd();
  }
}








void writer(int row,int x1,int x2,int x3,int wait,char fore1[],char fore2[],char fore3[]){
int i;
for(i=0;i<strlen(fore1);i++){
  lcd.setCursor((x1+i),row);
  lcd.print(fore1[i]);
  delay(wait);
}
for(i=0;i<strlen(fore2);i++){
  lcd.setCursor((x2+i),row+1);
  lcd.print(fore2[i]);
  delay(wait);
  }
  for(i=0;i<strlen(fore3);i++){
  lcd.setCursor((x3+i),row+2);
  lcd.print(fore3[i]);
  delay(wait);
  }
}
void erase(int x,int y,int wait,char fore1[],char fore2[]){
  int i;
  for(i=strlen(fore2);i>=0;i--){
  lcd.setCursor((x+i),2);
  lcd.print(" ");
  delay(wait);
  }
  for(i=strlen(fore1);i>=0;i--){
  lcd.setCursor((y+i),1);
  lcd.print(" ");
  delay(wait);
   }
}
