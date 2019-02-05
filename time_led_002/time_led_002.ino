#include <LedControl.h>

//LedControl(dataPin,clockPin,csPin,numDevices)
LedControl lc1 = LedControl(2, 4, 3, 1);
//How I have connected it on my board (only check it is Digital IO)
//DIN = blue   = 2
//CS  = purpel = 3
//CLK = grey   = 4

//add a delay variable for updates in between characters
unsigned long delaytime = 1000;
int counter = 9;


void setup() {
  // put your setup code here, to run once:
  //initialize Display, autodetect how many present and set to 0 (no LED on)
  for (int index = 0; index < lc1.getDeviceCount(); index++) {
    lc1.shutdown(index, false);
    lc1.setIntensity(index, 8);
    lc1.clearDisplay(0);
  }

}
void countDown() {
  int i = 9;

}

void writeonMatrix(int x) {
  int number = x*5;

  byte shownum[50] = {B00111110, B01000001, B01000001, B00111110, B00000000,
   B01000010, B01111111, B01000000, B00000000, B00000000,
   B01100010, B01010001, B01001001, B01000110, B00000000,
   B00100010, B01000001, B01001001, B00110110, B00000000,
   B00011000, B00010100, B00010010, B01111111, B00000000,
   B00100111, B01000101, B01000101, B00111001, B00000000,
   B00111110, B01001001, B01001001, B00110000, B00000000,
   B01100001, B00010001, B00001001, B00000111, B00000000,
   B00110110, B01001001, B01001001, B00110110, B00000000,
   B00000110, B01001001, B01001001, B00111110, B00000000};


  lc1.setRow(0, 0, shownum[number + 0]);
  lc1.setRow(0, 1, shownum[number + 1]);
  lc1.setRow(0, 2, shownum[number + 2]);
  lc1.setRow(0, 3, shownum[number + 3]);
  lc1.setRow(0, 4, shownum[number + 4]);


}
void loop() {
  // put your main code here, to run repeatedly:

  do{
    writeonMatrix(counter);
    counter--;
    delay(delaytime);
  }while ( counter > 0);
  
  
    writeonMatrix(8);
    delay(delaytime);
    lc1.clearDisplay(0);
    delay(delaytime);
    counter = 7;
  
}
