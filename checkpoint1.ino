#include <Keypad.h>
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
// 定義 Keypad 的按鍵
char keys[ROWS][COLS] = {

};
// 定義 Keypad 連到 Arduino 的接腳
byte rowPins[ROWS] = {5, 4, 3, 2};
// 連到 Keypad 的 4 個 Rows
byte colPins[COLS] = {9, 8, 7, 6};
// 連到 Keypad 的 4 個 Columns
// 建立 Keypad 物件
Keypad keypad =Keypad( makeKeymap(keys), rowPins,colPins, 4, 4 );
void setup(){
Serial.begin(9600);
}
void loop(){
char key = keypad.getKey(); // 讀取 Keypad的輸入
if (key != NO_KEY){
Serial.println(key);
}
}
