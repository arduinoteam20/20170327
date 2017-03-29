#include <SevSeg.h>
#include <Keypad.h>

SevSeg sevseg; 

void setup() {
   Serial.begin(9600); 
   byte numDigits =1;
   
   byte digitPins[] = {A4};
     byte segmentPins[] = {A5,11,12, 13, A0, A1, A2 ,A3};
   sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
}

const byte ROWS = 4;
const byte COLS = 4;
char key;
int k;
char keys[ROWS][COLS]={
  {'F', 'E', 'D', 'C'},
{'B','3','6', '9'},
{'A', '2', '5', '8'}, 
{'0', '1', '4', '7'}
};

byte rowPins[ROWS]={5, 4, 3, 2};
byte colPins[COLS]={9, 8, 7, 6};
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void loop() {
  key = keypad.getKey();
  
  if (key != NO_KEY)
  {
    if(key>='A' && key<='F')
       k=key-'A';
    else
       k=key-'0';
       
    Serial.println(key);
     sevseg.setNumber(k,1);
     sevseg.refreshDisplay(); 
  }
  else
   sevseg.refreshDisplay(); 
  


  
 
}
