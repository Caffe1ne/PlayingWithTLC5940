// Float mapping!
float map_double(double x, double in_min, double in_max, double out_min, double out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Calculate the various colors
int sinRed(float x, int y){
  float valUnconstrained = ((2 * 1.5) / pi * asin(sin(2 * pi / 1 * x + (pi / 2))) + 0.5);
  float val = constrain(valUnconstrained, 0.0, 1.0);
  if(y == 0 && DEBUG > 1){
    Serial.print(x);
    Serial.print(",");
    Serial.print(map_double(val, 0.0, 1.0, 0.0, 4095.0));
  }
  return map_double(val, 0.0, 1.0, 0, potValue);
}

int sinGreen(float x, int y){
  float valUnconstrained = ((2 * 1.5) / pi * asin(sin(2 * pi / 1 * x - (pi / 6))) + 0.5);
  float val = constrain(valUnconstrained, 0.0, 1.0);
   if(y == 0 && DEBUG > 1){
    Serial.print(",");
    Serial.print(map_double(val, 0.0, 1.0, 0, potValue));
   }
  return map_double(val, 0.0, 1.0, 0, potValue);
}

int sinBlue(float x, int y){
  float valUnconstrained = ((2 * 1.5) / pi * asin(sin(2 * pi / 1 * x - 5 * (pi / 6))) + 0.5);
  float val = constrain(valUnconstrained, 0.0, 1.0);
   if(y == 0 && DEBUG > 1){
    Serial.print(",");
    Serial.println(map_double(val, 0.0, 1.0, 0, potValue));
   }
  return map_double(val, 0.0, 1.0, 0, potValue);
}


void setColorLED(int numLED, int red, int green, int blue){
  chanRed[numLED] = red;
  chanGreen[numLED] = green;
  chanBlue[numLED] = blue;
  
  if(DEBUG > 2){
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
  /* Push values from arrays to the TLC library */ // Until I dig into the lib itself and find a cleaner way to do that...
  for(int i = 0; i < sizeOfArrays; i+=3){
    Tlc.set(i, chanRed[i/3]);
    Tlc.set(i+1, chanGreen[i/3]);
    Tlc.set(i+2, chanBlue[i/3]);
  }
  Tlc.update(); // Write values to chips and apply them
}

float getSpeed(){
  float temp = map (analogRead(A1), 20, 1020, 0, 1000);
  temp = 0.00005 * temp;
  return temp;
}
