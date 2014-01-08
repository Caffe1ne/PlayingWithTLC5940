// YES THIS FILE IS MESSY I KNOW

#include <Tlc5940.h>
#define DEBUG 2 // 0 == off, 1 == errors, 2 == more things, 3 == all the things
#define NUMBER_OF_LEDS 21 // Number of LEDS in use
#define MAX_PWM_VALUE 4095 // Maximum value of PWM driver. For TLC5940s that's 4095
#define potValue 4095

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
//int potValue; // ...and the potmeter for speed control

void setup(){
  Serial.begin(9600);
  Serial.print("Number of TLCs: ");
  Serial.println(NUM_TLCS);

  Tlc.init();
  Tlc.clear();
}

void loop(){
 for(float i = 1; i > 0; i -= getSpeed()){
//    potValue = map(analogRead(A0), 0, 1024, 0, MAX_PWM_VALUE);
  for(int y = 0; y < NUMBER_OF_LEDS; y++){
    float offset = (1.0/NUMBER_OF_LEDS)*y;
    setColorLED(y, sinRed(i+offset, y), sinGreen(i+offset, y), sinBlue(i+offset, y));
  }
  
  updateColors();
  delay(1);
  }
}
