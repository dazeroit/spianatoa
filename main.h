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
*  
*/

#include <AccelStepper.h>
#include "board.h"
#include "config.h"
#include "motors.h"

long next_step = 0;
bool invert = false;
bool active = false;
int current_state = 0;
long current_x_position = 0;
long current_y_position = 0;

void mainSetup() {
    setupMotors();
}

void mainLoop() {
    checkInputs();
    checkMotion();
}

void checkInputs(){
    checkStopSwitch();
    checkStopRequest();
    checkDirection();
    checkStartRequest();
}

void checkMotion() {
    if(active){
        stateControl();
    }
}

void checkDirection() {
    if(digitalRead(ENDSTOP_X_PIN) == ENDSTOP_X_ACTIVE_STATE){
        invert = !invert;
        current_state = 1;
    }
}

void checkStopSwitch(){
    if(digitalRead(ENDSTOP_Y_PIN) == ENDSTOP_Y_ACTIVE_STATE){
        stopMotion();
    }
}

void checkStopRequest() {
    if(digitalRead(STOP_BUTTON_PIN) == STOP_BUTTON_ACTIVE_STATE){
        stopMotion();
    }
}

void checkStartRequest() {
    if(digitalRead(START_BUTTON_PIN) == START_BUTTON_ACTIVE_STATE){
        startMotion();
    }
}

void stopMotion() {
    active = false;
}

void startMotion() {
    if(!active){
        homeAllAxis();
        current_x_position = 0;
        current_y_position = 0;
        active = true;
    }
}

void stateControl() {
    switch(current_state){
        case 0:
            state0();
            break;
        case 1:
            state1();
            break;
        case 2:
            state2();
            break;
    }
}

void state0() {
    if(invert){
        MotorX.setSpeed(-MOTOR_X_SPEED);
    }else{
        MotorX.setSpeed(MOTOR_X_SPEED);
    }
    moveAxisX();
}

void state1() {
    stopAxisX();
    current_state++;
    delay(500);
}

void state2() {
    moveAxisY();
    if(MotorY.distanceToGo() == 0){
        stopAxisY();
        incrementYMultiplier();
        current_state = 0;
        delay(500);
    }
}
