#include <LiquidCrystal_I2C.h>
#include <Password.h> //http://www.arduino.cc/playground/uploads/Code/Password.zip
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip
#include <Wire.h>
#include <string.h>


#define I2C_ADDR 0x27 
#define BACKLIGHT_PIN 3

const byte ROWS = 5; 
const byte COLS = 4; 
int state = 0 , choice = 0 , input = 0;

char a1,a2,a3,a4,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,d1,d2;
String A,B,C,D,E,F,G,go,went,gone;
int i=0;
// Define the Keymap
char keys[ROWS][COLS] = {
  {'F','G','#','.'},
  {'1','2','3','U'},
  {'4','5','6','D'},
  {'7','8','9','E'},
  {'L','0','R','N'}
};
byte rowPins[ROWS] = {30, 32, 34, 36 , 38};
byte colPins[COLS] = {46, 44, 42, 40};
// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String number="";
char numGlobal = ' ';

LiquidCrystal_I2C lcd(0x27, 20, 4);   //Module IIC/I2C Interface บางรุ่นอาจจะใช้ 0x3f

void setup(){
lcd.begin();
//lcd.noBacklight();   // ปิด backlight
lcd.backlight();    // เปิด backlight

Serial.begin(9600);
keypad.addEventListener(keypadEvent); //add an event listener for this keypad
}

void loop(){
keypad.getKey();
if(state==0){
  lcd.home();
  lcd.print("1.PEOPLE");
  lcd.setCursor(0, 1);
  lcd.print("2.MILES");
  lcd.setCursor(0, 2);
  lcd.print("3.METERS");
  lcd.setCursor(0, 3);
  lcd.print("4.STATUS");
  lcd.setCursor(10, 3);
  lcd.print(gone);
  Serial.println("Main MENU");
  sum_value();
}

if(state==1){
  
  if(numGlobal == '1'){ 
    choice = 1;                         //people
    lcd.home();
    lcd.print("1.PEOPLE UP");
    lcd.setCursor(0, 1);
    lcd.print("2.PELPLE DOWN");
    Serial.println("Menu1");
  }
  else if(numGlobal == '2'){            //mile
    choice = 2;
    lcd.home();
    lcd.print("1.MILES START");
    lcd.setCursor(0, 1);
    lcd.print("2.MILES END");
    Serial.println("Menu2");
  }
  else if(numGlobal == '3'){            //meter
    choice = 3;
    lcd.home();
    lcd.print("1.METER START");
    lcd.setCursor(0, 1);
    lcd.print("2.METERS END");
    Serial.println("Menu3");
  }
  else if(numGlobal == '4'){ //
    choice = 4;
    lcd.home();
    lcd.print("MILES START = ");
    lcd.setCursor(14,0);
    lcd.print(C);
    lcd.setCursor(0, 1);
    lcd.print("MILES END = ");
    lcd.setCursor(12,1);
    lcd.print(D);
    lcd.setCursor(0, 2);
    lcd.print("METERS START = ");
    lcd.setCursor(15,2);
    lcd.print(E);
    lcd.setCursor(0, 3);
    lcd.print("METERS END = ");
    lcd.setCursor(13,3);
    lcd.print(F);
    lcd.setCursor(18, 3);
    lcd.print("C1");
    Serial.println("Menu4");
  }
  else{
    state = 0;
  }
}

if(state == 2){
     if(numGlobal == '1' and choice == 1){       //คนขึ้น  
       input = 1;
       }
     else if(numGlobal == '2' and choice == 1){   //คนลง
       input = 2;  
       }
      else if(numGlobal == '1' and choice == 2){    //mileขึ้น 
       input = 3;
       }
      else if(numGlobal == '2' and choice == 2){    //mileลง 
       input = 4;
       }
      else if(numGlobal == '1' and choice == 3){    //meterขึ้น 
       input = 5;
       }
      else if(numGlobal == '2' and choice == 3){    //meterลง
       input = 6;   
       }
      else if(numGlobal == 'E' and choice == 4){ 
       state = 0;
       }
      else{
        state = 1;
        numGlobal = ' ';
      }   
     }
if(state == 3){
  if(input == 1){ 
    a1 = numGlobal;
    lcd.home();
    lcd.print(a1);
  }
  else if(input == 2){
    a2 = numGlobal;
    lcd.home();
    lcd.print(a2);
  }
  else if(input == 3){
    b1 = numGlobal;
    lcd.home();
    lcd.print(b1);
  }
  else if(input == 4){
    b2 = numGlobal;
    lcd.home();
    lcd.print(b2);
  }
  else if(input == 5){
    c1 = numGlobal;
    lcd.home();
    lcd.print(c1);
  }
  else if(input == 6){
    c2 = numGlobal;
    lcd.home();
    lcd.print(c2);
  }
}
if(state == 4){
  if(input == 1){
    a3 = numGlobal;
    lcd.home();
    lcd.print(a1);
    lcd.setCursor(1, 0);
    lcd.print(a3);
    lcd.setCursor(0, 1);
    lcd.print("Esc or Ent ?");
      }
   else if(input == 2){
    a4 = numGlobal;
    lcd.home();
    lcd.print(a2);
    lcd.setCursor(1, 0);
    lcd.print(a4);
    lcd.setCursor(0, 1);
    lcd.print("Esc or Ent ?");
      }
    else if(input == 3){
    b3 = numGlobal;
    lcd.home();
    lcd.print(b1);
    lcd.setCursor(1, 0);
    lcd.print(b3);
      }
    else if(input == 4){
    b4 = numGlobal;
    lcd.home();
    lcd.print(b2);
    lcd.setCursor(1, 0);
    lcd.print(b4);
      }
    else if(input == 5){
    c3 = numGlobal;
    lcd.home();
    lcd.print(c1);
    lcd.setCursor(1, 0);
    lcd.print(c3);
      }
    else if(input == 6){
    c4 = numGlobal;
    lcd.home();
    lcd.print(c2);
    lcd.setCursor(1, 0);
    lcd.print(c4);
      }
    }

    
if(state == 5){
    if(input == 1 or input == 2){
    enter();
    out();
      }
  
   else if(input == 3){
    b5 = numGlobal;
    lcd.home();
    lcd.print(b1);
    lcd.setCursor(1, 0);
    lcd.print(b3);
    lcd.setCursor(2, 0);
    lcd.print(b5);
      }
    else if(input == 4){
    b6 = numGlobal;
    lcd.home();
    lcd.print(b2);
    lcd.setCursor(1, 0);
    lcd.print(b4);
    lcd.setCursor(2, 0);
    lcd.print(b6);
      }
    else if(input == 5){
    c5 = numGlobal;
    lcd.home();
    lcd.print(c1);
    lcd.setCursor(1, 0);
    lcd.print(c3);
    lcd.setCursor(2, 0);
    lcd.print(c5);
    lcd.setCursor(0, 1);
    lcd.print("Esc or Ent ?");
      }
    else if(input == 6){
    c6 = numGlobal;
    lcd.home();
    lcd.print(c2);
    lcd.setCursor(1, 0);
    lcd.print(c4);
    lcd.setCursor(2, 0);
    lcd.print(c6);
    lcd.setCursor(0, 1);
    lcd.print("Esc or Ent ?");
      }
}
if(state == 6){
  if (input == 3){
    b7 = numGlobal;
    lcd.home();
    lcd.print(b1);
    lcd.setCursor(1, 0);
    lcd.print(b3);
    lcd.setCursor(2, 0);
    lcd.print(b5);
    lcd.setCursor(3, 0);
    lcd.print(b7);  
  }
  else if (input == 4){
    b8 = numGlobal;
    lcd.home();
    lcd.print(b2);
    lcd.setCursor(1, 0);
    lcd.print(b4);
    lcd.setCursor(2, 0);
    lcd.print(b6);
    lcd.setCursor(3, 0);
    lcd.print(b8);  
  }
  else if(input == 5 or input == 6){
    enter();
    out();
  }
}
if (state == 7){
   if (input == 3){
    b9 = numGlobal;
    lcd.home();
    lcd.print(b1);
    lcd.setCursor(1, 0);
    lcd.print(b3);
    lcd.setCursor(2, 0);
    lcd.print(b5);
    lcd.setCursor(3, 0);
    lcd.print(b7);
    lcd.setCursor(4, 0);
    lcd.print(b9);  
  }
  else if (input == 4){
    b10 = numGlobal;
    lcd.home();
    lcd.print(b2);
    lcd.setCursor(1, 0);
    lcd.print(b4);
    lcd.setCursor(2, 0);
    lcd.print(b6);
    lcd.setCursor(3, 0);
    lcd.print(b8);
    lcd.setCursor(4, 0);
    lcd.print(b10);   
  }
}
if (state == 8){
  if (input == 3){
    b11 = numGlobal;
    lcd.home();
    lcd.print(b1);
    lcd.setCursor(1, 0);
    lcd.print(b3);
    lcd.setCursor(2, 0);
    lcd.print(b5);
    lcd.setCursor(3, 0);
    lcd.print(b7);
    lcd.setCursor(4, 0);
    lcd.print(b9);
    lcd.setCursor(5, 0);
    lcd.print(b11);
    lcd.setCursor(0, 1);
    lcd.print("Esc or Ent ?");  
  }
  else if (input == 4){
    b12 = numGlobal;
    lcd.home();
    lcd.print(b2);
    lcd.setCursor(1, 0);
    lcd.print(b4);
    lcd.setCursor(2, 0);
    lcd.print(b6);
    lcd.setCursor(3, 0);
    lcd.print(b8);
    lcd.setCursor(4, 0);
    lcd.print(b10);
    lcd.setCursor(5, 0);
    lcd.print(b12);
    lcd.setCursor(0, 1);
    lcd.print("Esc or Ent ?");  
  }
}
if(state >= 9){
  if(input == 3 or input == 4){
    enter();
    out();
  }
}
}
  
  
  


void keypadEvent(KeypadEvent num){
  switch (keypad.getState()){
    case PRESSED:  
      lcd.begin();
      state++;
      numGlobal = num;
    break;
  }
}
void out(){
  if(numGlobal == 'E'){
    if(input == 1){
      a1 = ' ';
      a3 = ' ';
    }
    else if(input == 2){
      a2 = ' ';
      a4 = ' ';
    }
    else if(input == 3){
      b1 = ' ';
      b3 = ' ';
      b5 = ' ';
      b7 = ' ';
      b9 = ' ';
      b11 = ' ';
    }
    else if(input == 4){
      b2 = ' ';
      b4 = ' ';
      b6 = ' ';
      b8 = ' ';
      b10 = ' ';
      b12 = ' ';
    }
    else if(input == 5){
      c1 = ' ';
      c3 = ' ';
      c5 = ' ';
    }
    else if(input == 6){
      c2 = ' ';
      c4 = ' ';
      c6 = ' ';
    }
      state = 0;
  }
}
void enter(){
  if(numGlobal == 'N'){
    sum_value();
    calculate();
  state = 0;
  }
}
void sum_value(){
  A = String(a1)+String(a3);
  B = String(a2)+String(a4);
  C = String(b1)+String(b3)+String(b5)+String(b7)+String(b9)+String(b11);
  D = String(b2)+String(b4)+String(b6)+String(b8)+String(b10)+String(b12);
  E = String(c1)+String(c3)+String(c5);
  F = String(c2)+String(c4)+String(c6);
  Serial.println("Hi");
  Serial.println(A);
  Serial.println(B);
  Serial.println(C);
  Serial.println(D);
  Serial.println(E);
  Serial.println(F);
}
void calculate(){
  go = A.toInt();
  went = go.toInt();
  gone = went.toInt() - B.toInt();
}




