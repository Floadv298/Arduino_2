#include <LedControl.h>

//LedControl(dataPin,clockPin,csPin,numDevices)
LedControl lc1 = LedControl(2, 4, 3, 1);
//How I have connected it on my board (only check it is Digital IO)
//DIN = blue   = 2
//CS  = purpel = 3
//CLK = grey   = 4

//add a delay variable for updates in between characters
unsigned long delaytime = 1000;

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
  int numlow = (x%10)*5; //Modulo returns the lower number (divided by ten and keep the rest)
  int numhigh = (x/10) *5;  //divided by 10 retrun the high number (int cut the .xx away)
  
  if(numhigh == 0){
    numhigh = 50;
  }
    
  byte shownum[55] = {B00111110, B01000001, B01000001, B00111110, B00000000,
   B01000010, B01111111, B01000000, B00000000, B00000000,
   B01100010, B01010001, B01001001, B01000110, B00000000,
   B00100010, B01000001, B01001001, B00110110, B00000000,
   B00011000, B00010100, B00010010, B01111111, B00000000,
   B00100111, B01000101, B01000101, B00111001, B00000000,
   B00111110, B01001001, B01001001, B00110000, B00000000,
   B01100001, B00010001, B00001001, B00000111, B00000000,
   B00110110, B01001001, B01001001, B00110110, B00000000,
   B00000110, B01001001, B01001001, B00111110, B00000000,
   B00000000, B00000000, B00000000, B00000000, B00000000};


  lc1.setRow(0, 0, shownum[numhigh + 0]);
  lc1.setRow(0, 1, shownum[numhigh + 1]);
  lc1.setRow(0, 2, shownum[numhigh + 2]);
  lc1.setRow(0, 3, shownum[numhigh + 3]);
  lc1.setRow(0, 4, shownum[numlow + 0]);
  lc1.setRow(0, 5, shownum[numlow + 1]);
  lc1.setRow(0, 6, shownum[numlow + 2]);
  lc1.setRow(0, 7, shownum[numlow + 3]);

}
void loop() {
  // put your main code here, to run repeatedly:
  int counter = 89;
  do{
    writeonMatrix(counter);
    counter--;
    delay(delaytime);
  }while ( counter > 0);
  
  
  //writeonMatrix(8);
  //delay(delaytime);
  lc1.clearDisplay(0);
  delay(delaytime);
  
  
}
