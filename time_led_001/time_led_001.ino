#include <LedControl.h>
//#include <binary.h>
//#include <avr/pgmspace.h>  //for ProgMem

//LedControl(dataPin,clockPin,csPin,numDevices)
LedControl lc1=LedControl(2,4,3,1);
//How I have connected it on my board (only check it is Digital IO)
//DIN = blue   = 2
//CS  = purpel = 3
//CLK = grey   = 4

//add a delay variable for updates in between characters
unsigned long delaytime=1000;



void setup() {
  // put your setup code here, to run once:
  //initialize Display, autodetect how many present and set to 0 (no LED on)
  for(int index=0;index<lc1.getDeviceCount();index++){
    lc1.shutdown(index,false);
    lc1.setIntensity(index,8);
    lc1.clearDisplay(0);
  }

}
void countDown(){
  int i=9;
  
}

void writeonMatrix(){

//character data
byte a0[5]={B00111110, B01000001, B01000001, B00111110, B00000000}; // 0
byte a1[5]={B01000010, B01111111, B01000000, B00000000, B00000000}; // 1
byte a2[5]={B01100010, B01010001, B01001001, B01000110, B00000000}; // 2
byte a3[5]={B00100010, B01000001, B01001001, B00110110, B00000000}; // 3
byte a4[5]={B00011000, B00010100, B00010010, B01111111, B00000000}; // 4
byte a5[5]={B00100111, B01000101, B01000101, B00111001, B00000000}; // 5
byte a6[5]={B00111110, B01001001, B01001001, B00110000, B00000000}; // 6
byte a7[5]={B01100001, B00010001, B00001001, B00000111, B00000000}; // 7
byte a8[5]={B00110110, B01001001, B01001001, B00110110, B00000000}; // 8
byte a9[5]={B00000110, B01001001, B01001001, B00111110, B00000000}; // 9

  lc1.setRow(0,0,a9[0]);
  lc1.setRow(0,1,a9[1]);
  lc1.setRow(0,2,a9[2]);
  lc1.setRow(0,3,a9[3]);
  lc1.setRow(0,4,a9[4]);

 
}
void loop() {
  // put your main code here, to run repeatedly:
  writeonMatrix();
  delay(delaytime);
  lc1.clearDisplay(0);
  delay(delaytime);
    
}
