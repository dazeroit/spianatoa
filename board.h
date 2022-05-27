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

#define BOARD_TYPE CNC_SHIELD_V3

#define MOTOR_X_ENABLE_PIN 8
#define MOTOR_Y_ENABLE_PIN MOTOR_X_ENABLE_PIN
#define MOTOR_Z_ENABLE_PIN MOTOR_X_ENABLE_PIN
#define MOTOR_A_ENABLE_PIN MOTOR_X_ENABLE_PIN

#define MOTOR_X_ENABLE_INVERT false
#define MOTOR_Y_ENABLE_INVERT MOTOR_X_ENABLE_INVERT
#define MOTOR_Z_ENABLE_INVERT MOTOR_X_ENABLE_INVERT
#define MOTOR_A_ENABLE_INVERT MOTOR_X_ENABLE_INVERT

#define MOTOR_X_STEP_INVERT false
#define MOTOR_Y_STEP_INVERT false
#define MOTOR_Z_STEP_INVERT false
#define MOTOR_A_STEP_INVERT false

#define MOTOR_X_DIR_INVERT false
#define MOTOR_Y_DIR_INVERT false
#define MOTOR_Z_DIR_INVERT false
#define MOTOR_A_DIR_INVERT false

#define MOTOR_X_STEP_PIN 2
#define MOTOR_Y_STEP_PIN 3
#define MOTOR_Z_STEP_PIN 4
#define MOTOR_A_STEP_PIN 12

#define MOTOR_X_DIR_PIN 5
#define MOTOR_Y_DIR_PIN 6
#define MOTOR_Z_DIR_PIN 7
#define MOTOR_A_DIR_PIN 13

#define ENDSTOP_X_PIN 9
#define ENDSTOP_Y_PIN 10
#define ENDSTOP_Z_PIN 11

#define START_BUTTON_PIN A2
#define START_BUTTON_ACTIVE_STATE LOW

#define STOP_BUTTON_PIN A0
#define STOP_BUTTON_ACTIVE_STATE LOW