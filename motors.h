/**   
*            _                   _  _   _  
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

AccelStepper MotorX(MOTOR_X_INTERFACE,MOTOR_X_STEP_PIN,MOTOR_X_DIR_PIN);
AccelStepper MotorY(MOTOR_Y_INTERFACE,MOTOR_Y_STEP_PIN,MOTOR_Y_DIR_PIN);

long y_multiplier = 1 ;

void setupMotors() {

    MotorX.setAcceleration(MOTOR_X_ACCELERATION);
    MotorX.setMaxSpeed(MOTOR_X_MAX_SPEED);
    MotorX.setSpeed(MOTOR_X_SPEED);
    MotorX.disableOutputs();

    MotorY.setAcceleration(MOTOR_Y_ACCELERATION);
    MotorY.setMaxSpeed(MOTOR_Y_MAX_SPEED);
    MotorY.setSpeed(MOTOR_Y_SPEED);
    MotorY.disableOutputs();
    
}


void homeAxisX() {
    MotorX.setCurrentPosition(0);
}
void homeAxisY() {
    MotorY.setCurrentPosition(0);
}
void homeAllAxis() {
    homeAxisX();
    homeAxisY();
}

void moveAxisX() {
    MotorX.runSpeed();
}

void moveAxisY() {
    MotorY.moveTo(Y_TRAVEL_DISTANCE * y_multiplier);
    MotorY.run();
}

void incrementYMultiplier(){
    y_multiplier++;
}

void stopAxisX() {
    MotorX.stop();
}
void stopAxisY() {
    MotorY.stop();
}