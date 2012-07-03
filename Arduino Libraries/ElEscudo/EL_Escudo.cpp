/*
  EL_Escudo.cpp - EL Escudo library
  Written by Ryan Owens for SparkFun Electronics

  This library is released under the 'Beer Me' license, so use it however you
  with. Just buy me a beer if we ever meet!
  
  Edits by Paul Krakow to make this library work with the Arduino 1.0 IDE
  And to get the "on" API call to work
 
*/

/******************************************************************************
 * Includes
 ******************************************************************************/

#include "Arduino.h"
#include "EL_Escudo.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/

/******************************************************************************
 * Constructors
 ******************************************************************************/

/******************************************************************************
 * User API
 ******************************************************************************/

void EL_EscudoClass::on(char channel)
{
	pinMode(channel, OUTPUT);
	digitalWrite(channel, HIGH); 
}

void EL_EscudoClass::off(char channel)
{
	pinMode(channel, OUTPUT);
	digitalWrite(channel, LOW);
}

void EL_EscudoClass::all_on(void)
{
	for(int i=0; i<4; i++){
	  EL.on(i*2+A);
	  EL.on(i*2+1+A);
	  delayMicroseconds(20);
	  EL.off(i*2+A);
	  EL.off(i*2+1+A);   
	}
}

void EL_EscudoClass::all_off(void)
{
	for(int i=A; i<10; i++)EL.off(i);
	EL.off(7);
}

void EL_EscudoClass::fade_in(char channel)
{
	for(int brightness=0; brightness<=pulse_width; brightness++){
		for(int duration=0; duration<5; duration++){
			EL.on(channel);
			delay(brightness);
			EL.off(channel);
			delay(pulse_width-brightness);
		}
	}
	EL.on(channel);
}

void EL_EscudoClass::fade_out(char channel)
{
	for(int brightness=pulse_width; brightness>=0; brightness--){
		for(int duration=0; duration<5; duration++){
			EL.on(channel);
			delay(brightness);
			EL.off(channel);
			delay(pulse_width-brightness);
		}
	}
}

void EL_EscudoClass::pulse(char channel)
{
	EL.fade_in(channel);
	EL.fade_out(channel);
}

EL_EscudoClass EL;
