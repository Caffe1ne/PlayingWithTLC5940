#include "Tlc5940.h"
#define DEBUG 2 // 0 == off, 1 == errors, 2 == all the things

int chanRed[NUM_TLCS*16/3];
int chanGreen[NUM_TLCS*16/3];
int chanBlue[NUM_TLCS*16/3];
int sizeOfArrays= (NUM_TLCS*16) - (NUM_TLCS*16)%3;

int redTest = 0;
int greenTest = 2048;
int blueTest = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println(NUM_TLCS);
  Serial.println(sizeOfArrays);
  
  Tlc.init();
  Tlc.clear();
  
  for(int i = 0; i < 5; i++){
    setColorLED(i, redTest, greenTest, blueTest);
  }
  updateColors();  
}

void setColorLED(int numLED, int red, int green, int blue){
  chanRed[numLED] = red;
  chanGreen[numLED] = green;
  chanBlue[numLED] = blue;
  
  if(DEBUG > 1){
    Serial.print("LED number ");
    Serial.print(numLED);
    Serial.print(" now has RGB values ");
    Serial.print(red);
    Serial.print(", ");
    Serial.print(green);
    Serial.print(", ");
    Serial.println(blue);
  }
}

void updateColors(){
  Tlc.clear();  // Clear out the old values
  delay(20);  // Give it time to clear up

  /* Push values from arrays to the TLC library */ // Until I dig into the lib itself and find a cleaner way to do that...
  for(int i = 0; i < sizeOfArrays; i+=3){
    Tlc.set(i, chanRed[i/3]);
    Tlc.set(i+1, chanGreen[i/3]);
    Tlc.set(i+2, chanBlue[i/3]);
  }

  delay(20); // Think for a bit
  Tlc.update(); // Write values to chips and apply them
}

void loop()
{
}
