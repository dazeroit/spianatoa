/**   
*             _                   _  _   _  
*   ___ _ __ (_) __ _ _ __   __ _| |(_)_(_) __ _ 
*  / __| '_ \| |/ _` | '_ \ / _` | __/ _ \ / _` |
*  \__ \ |_) | | (_| | | | | (_| | || (_) | (_| |
*  |___/ .__/|_|\__,_|_| |_|\__,_|\__\___/ \__,_|
*      |_|                                       
*      
*  Copyright (c) 2022  Dazero.it / WhiteGhost
*  Author : ivan.maruca@gmail.com
*  Version : 0.0.1
*  
*  Permission is hereby granted, free of charge, to any person
*  obtaining a copy of this software and associated documentation
*  files (the "Software"), to deal in the Software without
*  restriction, including without limitation the rights to use,
*  copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the
*  Software is furnished to do so, subject to the following
*  conditions:
*  
*  The above copyright notice and this permission notice shall be
*  included in all copies or substantial portions of the Software.
*  
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
*  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
*  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
*  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
*  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
*  OTHER DEALINGS IN THE SOFTWARE.
*  
*  --------------------------------------------------------------
*  HARDWARE NECESSARIO :
*  
*  1x Arduino UNO
*  1x Arduino CNC SHIELD v3
*  2x Stepper Driver : DRV8825 o A4988
*  2x Motori Stepper
*  3x Micro Interruttori
*  
*  --------------------------------------------------------------
*  LIBRERIE NESECESSARIE :    
*  
*  AccelStepper 1.61.0 -> https://github.com/swissbyte/AccelStepper
*  Button 1.0.0 -> https://downloads.arduino.cc/libraries/github.com/madleech/Button-1.0.0.zip
*  
*  --------------------------------------------------------------    
*/

#include <AccelStepper.h>
#include <Button.h>
#include "board.h"
#include "config.h"

//#define DEBUG

AccelStepper MotorX(MOTOR_X_INTERFACE,MOTOR_X_STEP_PIN,MOTOR_X_DIR_PIN);
AccelStepper MotorY(MOTOR_Y_INTERFACE,MOTOR_Y_STEP_PIN,MOTOR_Y_DIR_PIN);

Button endstopX(ENDSTOP_X_PIN);
Button endstopY(ENDSTOP_Y_PIN);
Button startButton(START_BUTTON_PIN);
Button stopButton(STOP_BUTTON_PIN);

static uint8_t currentState = 0;
volatile bool enableMotion = false;
bool isMotorEnabled = false;
float currentMotorXSpeed = MOTOR_X_SPEED;
// --------------------------------------------------------------
// SETUP INGRESSI/USCITE
// --------------------------------------------------------------
void setupIO(){
  pinMode(MOTOR_ENABLE_PIN,OUTPUT);
  pinMode(ENDSTOP_X_PIN,ENDSTOP_X_MODE);
  pinMode(ENDSTOP_Y_PIN,ENDSTOP_Y_MODE);
  pinMode(START_BUTTON_PIN,START_BUTTON_MODE);
  pinMode(STOP_BUTTON_PIN,STOP_BUTTON_MODE);
  
  endstopX.begin();
  endstopY.begin();
  startButton.begin();
  stopButton.begin();

  #if defined(DEBUG)
    Serial.println("setupIO checked");
  #endif
}
// --------------------------------------------------------------
// SETUP MOTORI
// --------------------------------------------------------------
void setupSteppers(){
  MotorX.setEnablePin(MOTOR_ENABLE_PIN);
  MotorX.setPinsInverted(false, false, true);
  MotorX.setAcceleration(MOTOR_X_ACCELERATION);
  MotorX.setMaxSpeed(MOTOR_X_MAX_SPEED);
  MotorX.setSpeed(MOTOR_X_SPEED);

  MotorY.setEnablePin(MOTOR_ENABLE_PIN);
  MotorY.setPinsInverted(false, false, true);
  MotorY.setAcceleration(MOTOR_X_ACCELERATION);
  MotorY.setMaxSpeed(MOTOR_Y_MAX_SPEED);
  MotorY.setSpeed(MOTOR_Y_SPEED);

  #if defined(DEBUG)
    Serial.println("setupStepper checked");
  #endif
}
// --------------------------------------------------------------
// CONTROLLO FINECORSA Y
// --------------------------------------------------------------
void checkEndstopY() {
  if(endstopY.pressed()){
    enableMotion = false ;
  }
}
// --------------------------------------------------------------
// CONTROLLO FINECORSA X
// --------------------------------------------------------------
bool checkEndstopX() {
  bool pressed = endstopX.pressed();
  if(pressed){
    float currentSpeed = MotorX.speed();
    if(currentSpeed > 0){
      currentMotorXSpeed = -MOTOR_X_SPEED ;
    }else{
      currentMotorXSpeed= MOTOR_X_SPEED ;
    }
  }
  return pressed;
}
// --------------------------------------------------------------
// STOP MOROR X
// --------------------------------------------------------------
void stopMotorX() {
  #if defined(DEBUG)
    Serial.println("stopMotorX...");
  #endif
  if(MotorX.isRunning()){
    #if defined(DEBUG)
      Serial.println("stopMotorX checked");
    #endif
    MotorX.stop();
    MotorY.move(MOTOR_Y_TRAVEL_DISTANCE);
    currentState++;
  }
}
// --------------------------------------------------------------
// START MOTOR X
// --------------------------------------------------------------
void startMotorX() {
  #if defined(DEBUG)
    Serial.println("startMotorX");
    Serial.print("motor x speed : ");Serial.println(MotorX.speed());
  #endif
  MotorX.setSpeed(currentMotorXSpeed);
  MotorX.runSpeed();
}
// --------------------------------------------------------------
// STOP MOTOR Y
// --------------------------------------------------------------
void stopMotorY() {
  #if defined(DEBUG)
    Serial.println("stopMotorY...");
  #endif
  //if(MotorY.isRunning()){
    #if defined(DEBUG)
      Serial.println("stopMotorY checked");
    #endif
    MotorY.stop();
    currentState++;
  //}
}
// --------------------------------------------------------------
// START MOTOR Y
// --------------------------------------------------------------
void startMotorY() {
  #if defined(DEBUG)
    Serial.println("startMotorY");
    Serial.print("motor y distance to go : ");Serial.println(MotorY.distanceToGo());
  #endif
  if(MotorY.distanceToGo() == 0){
    currentState++;
  }
  MotorY.run();
}
// --------------------------------------------------------------
// START MOTION E CHECK STATI
// --------------------------------------------------------------
void startMotion() {
  #if defined(DEBUG)
    Serial.println(">>>> START MOTION");
  #endif
  if(!isMotorEnabled){
    MotorX.enableOutputs();
    MotorX.setCurrentPosition(0);
    MotorY.enableOutputs();
    MotorY.setCurrentPosition(0);
    isMotorEnabled = true;
  }
  #if defined(DEBUG)
    Serial.print("CURRENT STATE : ");Serial.println(currentState);
  #endif
  switch(currentState){
    case 0:
      startMotorX();
      if(checkEndstopX()){
        currentState++;
      }
      break;
    case 1:
      stopMotorX();
      break;
    case 2:
      startMotorY();
      break;
    case 3:
      stopMotorY();
      break;
  }
  if(currentState > 3){
    currentState = 0;
  }
}
// --------------------------------------------------------------
// STOP MOTION
// --------------------------------------------------------------
void stopMotion() {
  #if defined(DEBUG)
    Serial.println(">>>> STOP MOTION");
  #endif
  MotorX.stop();
  MotorY.stop();
  MotorX.disableOutputs();
  MotorY.disableOutputs();
  isMotorEnabled = false ;
  currentState = 0;
}
// --------------------------------------------------------------
// LETTURA INGRESSI
// --------------------------------------------------------------
void readInputs() {
  #if defined(DEBUG)
    Serial.println("readInputs");
  #endif
  if(startButton.pressed()){
    enableMotion = true ;
  }
  if(stopButton.pressed()){
    enableMotion = false ;
  }
   #if defined(DEBUG)
    Serial.print("enableMotion -> ");Serial.println(enableMotion);
  #endif
}
// --------------------------------------------------------------
// MAIN SETUP 
// --------------------------------------------------------------
void setup() {
  #if defined(DEBUG)
    Serial.begin(9600);
    Serial.println("DEBUG ATTIVO !");
  #endif
  setupIO();
  setupSteppers();
  #if defined(DEBUG)
    Serial.println("main setup checked");
  #endif
}
// --------------------------------------------------------------
// MAIN LOOP
// --------------------------------------------------------------
void loop() {
  #if defined(DEBUG)
    Serial.println(">>> begin main loop <<<");
  #endif
  readInputs();
  checkEndstopY();
  if(enableMotion){
    startMotion();
  }else{
    stopMotion();
  }
  #if defined(DEBUG)
    Serial.println(">>> end main loop <<<");
    Serial.println("");
    delay(1000);
  #endif
}
