// YES THIS FILE IS MESSY I KNOW

#include "Tlc5940.h"
#define DEBUG 1 // 0 == off, 1 == errors, 2 == all the things
#define NUMBER_OF_LEDS 5 // Number of LEDS in use
#define MAX_PWM_VALUE 4095 // Maximum value of PWM driver. For TLC5940s that's 4095

float pi = 22/7; // Self-explainatory

/* Offsets in relation to stuff */
float offsetRed = -pi/2;
float offsetGreen = (pi/3)*4 - pi/2;
float offsetBlue = (pi/3)*8 - pi/2;

/* Initialize arrays */
int chanRed[NUM_TLCS*16/3];
int chanGreen[NUM_TLCS*16/3];
int chanBlue[NUM_TLCS*16/3];
int sizeOfArrays= (NUM_TLCS*16) - (NUM_TLCS*16)%3; // Make sure the array's fit for RGB LEDs and not any accidental RG LEDs

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
//  delay(20);  // Give it time to clear up

  /* Push values from arrays to the TLC library */ // Until I dig into the lib itself and find a cleaner way to do that...
  for(int i = 0; i < sizeOfArrays; i+=3){
    Tlc.set(i, chanRed[i/3]);
    Tlc.set(i+1, chanGreen[i/3]);
    Tlc.set(i+2, chanBlue[i/3]);
  }

//  delay(20); // Think for a bit
  Tlc.update(); // Write values to chips and apply them
}

void loop()
{
  for(float i = 0; i < 360; i+=5.0){
    for(int y = 0; y < NUMBER_OF_LEDS; y++){
      setColorLED(y, sinRed(i+(360/NUMBER_OF_LEDS*y)), sinGreen(i+(360/NUMBER_OF_LEDS*y)), sinBlue(i+(360/NUMBER_OF_LEDS*y)));
    }
    
    /*for(int y = 0; y < NUMBER_OF_LEDS; y++){
      setColorLED(y, sinRed(i), sinGreen(i), sinBlue(i));
    }*/
    
    updateColors();
    delay(10);
  }
  
}
