/**
 * main.cpp
 *
 *  @date Created at:	12/02/2024, 22:58:41
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * #######################################################################
 *   Copyright (C) Pedro Igor B. S 2021
 * -------------------------------------------------------------------
 *
 *   Licença: GNU GPL 3
 * -------------------------------------------------------------------
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation; version 2 of the
 *   License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 * -------------------------------------------------------------------
 * #######################################################################
 *
 * Speed and direction control by Arduino
 * look at https://github.com/pedro-ibs/bdesc-s10e-rtr-example-control for
 * more information.
 *
 */




/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include <Arduino.h>
#include <Servo.h>

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
#define MOTOR_STOP                    ( 1500			)
#define MOTOR_CLOCKWISE_MIN           ( 1600      )
#define MOTOR_CLOCKWISE_MAX           ( 1900      )
#define MOTOR_ANTICLOCKWISE_MIN       ( 1400      )
#define MOTOR_ANTICLOCKWISE_MAX       ( 1000      )
#define STEP_DELAY_FOR_ANTICLOCKWISE  ( 100       )
#define INTERRUPCAO_PIN               ( 3			    )
#define SERVO_PIN                     ( 9			    )
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
Servo esc;
static unsigned int uiPwmPeriod		      = MOTOR_STOP;
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void bind( void );
void anticlockwise( void );
void clockwise( void );
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/


void setup( void ) {

	Serial.begin( 115200 );
  
  bind();

}


void loop() {
  
  clockwise();
  esc.writeMicroseconds( MOTOR_STOP );
  delay( 1000 );  

  anticlockwise();
  esc.writeMicroseconds( MOTOR_STOP );
  delay( 1000 );  

}

/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*--------------------------------------------------------------------- Local Functions ------------------------------------------------------------------*/
/*########################################################################################################################################################*/

void bind( void ){
  if( esc.attached() == false ){
    esc.attach( SERVO_PIN );
  }

  esc.writeMicroseconds( MOTOR_STOP );
  delay( 200 );
}



void anticlockwise( void ){

  esc.writeMicroseconds( MOTOR_STOP );
  delay( STEP_DELAY_FOR_ANTICLOCKWISE );

  esc.writeMicroseconds( MOTOR_ANTICLOCKWISE_MAX );
  delay( STEP_DELAY_FOR_ANTICLOCKWISE );

  esc.writeMicroseconds( MOTOR_STOP );
  delay( STEP_DELAY_FOR_ANTICLOCKWISE );


  for (uint16_t p = MOTOR_ANTICLOCKWISE_MIN; p>MOTOR_ANTICLOCKWISE_MAX; p--) {
    esc.writeMicroseconds( p );
    delay( 5 );
  }

  for (uint16_t p = MOTOR_ANTICLOCKWISE_MAX; p<MOTOR_ANTICLOCKWISE_MIN; p++) {
    esc.writeMicroseconds( p );
    delay( 5 );
  }

}


void clockwise( void ){
  for (uint16_t p = MOTOR_CLOCKWISE_MIN; p<MOTOR_CLOCKWISE_MAX; p++) {
    esc.writeMicroseconds( p );
    delay( 5 );
  }

  for (uint16_t p = MOTOR_CLOCKWISE_MAX; p>MOTOR_CLOCKWISE_MIN; p--) {
    esc.writeMicroseconds( p );
    delay( 5 );
  }

}

