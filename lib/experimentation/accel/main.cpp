//Arduino 1.0+ Only!
//Arduino 1.0+ Only!

#include <Wire.h>
#include <stdlib.h>
#include <time.h>
#include "ADXL345.h"


ADXL345 adxl; //variable adxl is an instance of the ADXL345 library

void setup(){
  srand(time(NULL));
  Serial.begin(9600);
  adxl.powerOn();

  //set activity/ inactivity thresholds (0-255)
  adxl.setActivityThreshold(75); //62.5mg per increment
  adxl.setInactivityThreshold(75); //62.5mg per increment

  //look of activity movement on this axes - 1 == on; 0 == off
  adxl.setActivityX(1);
  adxl.setActivityY(1);
  adxl.setActivityZ(1);

  //look of inactivity movement on this axes - 1 == on; 0 == off
  adxl.setInactivityX(1);
  adxl.setInactivityY(1);
  adxl.setInactivityZ(1);

  //look of tap movement on this axes - 1 == on; 0 == off
  adxl.setTapDetectionOnX(0);
  adxl.setTapDetectionOnY(0);
  adxl.setTapDetectionOnZ(1);

  //set values for what is a tap, and what is a double tap (0-255)
  adxl.setTapThreshold(50); //62.5mg per increment
  adxl.setTapDuration(15); //625μs per increment
  adxl.setDoubleTapLatency(80); //1.25ms per increment
  adxl.setDoubleTapWindow(200); //1.25ms per increment

  //set values for what is considered freefall (0-255)
  adxl.setFreeFallThreshold(7); //(5 - 9) recommended - 62.5mg per increment
  adxl.setFreeFallDuration(10); //(20 - 70) recommended - 5ms per increment

  //setting all interupts to take place on int pin 1
  //I had issues with int pin 2, was unable to reset it
  adxl.setInterruptMapping( ADXL345_INT_SINGLE_TAP_BIT,  ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_DOUBLE_TAP_BIT,  ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_FREE_FALL_BIT,  ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_ACTIVITY_BIT,   ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_INACTIVITY_BIT,  ADXL345_INT1_PIN );

  //register interupt actions - 1 == on; 0 == off
  adxl.setInterrupt( ADXL345_INT_SINGLE_TAP_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_DOUBLE_TAP_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_FREE_FALL_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_ACTIVITY_BIT,  1);
  adxl.setInterrupt( ADXL345_INT_INACTIVITY_BIT, 0);
}

bool lookForActivity = false;
const char * words[] = {
      "Boom",
      "Banger",
      "Dropper",
};
void loop() {

  //Boring accelerometer stuff
  int x,y,z;
  adxl.readAccel(&x, &y, &z); //read the accelerometer values and store them in variables x,y,z

  // Output x,y,z values - Commented out
  //Serial.print(x);
  //Serial.print(y);
  //Serial.println(z);


  //Fun Stuff!
  //read interrupts source and look for triggerd actions

  //getInterruptSource clears all triggered actions after returning value
  //so do not call again until you need to recheck for triggered actions
  byte interrupts = adxl.getInterruptSource();

  // freefall
  if(adxl.triggered(interrupts, ADXL345_FREE_FALL)){
    lookForActivity = true;
    return;
  }

  //activity
  if(adxl.triggered(interrupts, ADXL345_ACTIVITY)){
    if (lookForActivity) {
      lookForActivity = false;
      int r = rand() % 3;
      Serial.println(words[r]);
      //Serial.println("farts");
    }
    return;
  }

  //inactivity
  if(adxl.triggered(interrupts, ADXL345_INACTIVITY)){
    //add code here to do when inactivity is sensed
  }

  //double tap
  if(adxl.triggered(interrupts, ADXL345_DOUBLE_TAP)){
    //add code here to do when a 2X tap is sensed
  }

  //tap
  if(adxl.triggered(interrupts, ADXL345_SINGLE_TAP)){
    //add code here to do when a tap is sensed
  }

}
