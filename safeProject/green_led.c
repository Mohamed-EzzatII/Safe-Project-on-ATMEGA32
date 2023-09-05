

 /******************************************************************************
 *
 * Module: RED_LED
 *
 * File Name: red_red.c
 *
 * Description: Source file for the RED_LED driver
 *
 * Author: Mohamed Ezzat
 *
 * Created on: April 24, 2023
 *
 * Version : v1.0.1
 *
 *******************************************************************************/

/************************Libraries and inclusions*******************************/

#include"common_macros.h"
#include<avr/io.h>
#include"green_led.h"
#include"gpio.h"

/*******************************************************************************/

/*******************************************************************************/

/**********************************Functions************************************/

/*
 * Description :
 * A function to initialize the GRN_LED
 */
void GRN_LED_init(void)
{
	/*Make the GRNLED pin output pin*/
	GPIO_setupPinDirection(GRN_LED_PORT,GRN_LED_PIN,PIN_OUTPUT);

	/*Turn off the GRN_LED*/
	GPIO_writePin(GRN_LED_PORT,GRN_LED_PIN,PIN_INPUT);
}

/*
 * Description :
 * A function to turn on the GRN_LED
 */
void GRN_LED_on(void)
{
	/*Turn on the RED_LED*/
	GPIO_writePin(GRN_LED_PORT,GRN_LED_PIN,PIN_OUTPUT);
}

/*
 * Description :
 * A function to turn off theGRN_LED
 */
void GRN_LED_off(void)
{
	/*Turn off the RED_LED*/
	GPIO_writePin(GRN_LED_PORT,GRN_LED_PIN,PIN_INPUT);
}
