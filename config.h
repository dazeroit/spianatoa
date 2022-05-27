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
// --------------------------------------------------------------

// --------------------------------------------------------------
//                        CONFIGURAZIONE
// --------------------------------------------------------------


// --------------------------------------------------------------
// MOTORE X
// --------------------------------------------------------------
#define MOTOR_X_INTERFACE AccelStepper::DRIVER
#define MOTOR_X_ACCELERATION 5000
#define MOTOR_X_MAX_SPEED 500
#define MOTOR_X_SPEED 100
// --------------------------------------------------------------
// MOTORE Y
// --------------------------------------------------------------
#define MOTOR_Y_INTERFACE AccelStepper::DRIVER
#define MOTOR_Y_ACCELERATION 5000
#define MOTOR_Y_MAX_SPEED 500
#define MOTOR_Y_SPEED 100
// --------------------------------------------------------------
// MOTORE Z
// --------------------------------------------------------------
#define MOTOR_Z_INTERFACE AccelStepper::DRIVER
#define MOTOR_Z_ACCELERATION 5000
#define MOTOR_Z_MAX_SPEED 500
#define MOTOR_Z_SPEED 100
// --------------------------------------------------------------
// MOTORE A
// --------------------------------------------------------------
#define MOTOR_A_INTERFACE AccelStepper::DRIVER
#define MOTOR_A_ACCELERATION 5000
#define MOTOR_A_MAX_SPEED 500
#define MOTOR_A_SPEED 100

// --------------------------------------------------------------
// FINECORSA
// --------------------------------------------------------------

#define ENDSTOP_X_ACTIVE_STATE HIGH
#define ENDSTOP_Y_ACTIVE_STATE HIGH

// --------------------------------------------------------------
// LOGIC
// --------------------------------------------------------------

#define Y_TRAVEL_DISTANCE 500
#define MAX_NUMBER_OF_STATE 2
