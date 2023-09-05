/******************************************************************************
 *
 * Layer: Application Layer
 *
 * File Name: app.c
 *
 * Description: source file for the app
 *
 * Author: Mohamed Ezzat
 *
 * Created on: 05/09/2023
 *
 * Version : v1.0.1
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  Inclusions                                  *
 *******************************************************************************/

#include"lcd.h"
#include"keypad.h"
#include"red_led.h"
#include"green_led.h"
#include"app.h"
#include<util/delay.h>

/*******************************************************************************
 *                              Global Variables	                           *
 *******************************************************************************/

static uint8 g_password[] = {1,2,3,4};

/*******************************************************************************
 *                            Local Functions Prototypes                       *
 *******************************************************************************/

static void APP_voidMainMenuScreen();
static void APP_voidTruePasswordScreen();
static void APP_voidOpenSafeScreen();
static void APP_voidChangePasswordScreen();
static void APP_voidChangePassword();
static void APP_voidWrongPasswordScreen(uint8 illetrations);
static void APP_voidThiefAlert();
static void APP_voidTruePasswordScreen();

/*******************************************************************************
 *                             Functions definition                            *
 *******************************************************************************/

/******************************************************/
/********A function to initialize the Application******/
void APP_voidInit(){
	LCD_init();
	GRN_LED_init();
	RED_LED_init();
}

/*****************************************************/
/********A function to display the 1st screen*********/
void APP_voidWelcomeScreen(){

	/* display "Welcome my user" */
	LCD_clearScreen();
	LCD_displayString("Welcome my user");
	_delay_ms(LONG_DELAY);

	/* Move to the next window ( Main Menu Screen )*/
	APP_voidMainMenuScreen();
}

/*****************************************************/
/********A function to display the main menu*********/
static void APP_voidMainMenuScreen(){

	/* display : -
	 * "1] open safe"
	 * "2] Change Pass"
	 */
	LCD_clearScreen();
	LCD_displayString("1] open safe");
	LCD_moveCursor(1, 0);
	LCD_displayString("2] Change Pass");

	/* Get the user decision */
	uint8 pressedKey = KEYPAD_getPressedKey();

	/* User choice is to open safe */
	if(pressedKey == 1)
	{
		/* Move to open safe screen*/
		APP_voidOpenSafeScreen();
	}

	/* User choice is to change password */
	else if(pressedKey == 2)
	{
		/* Move to change password screen */
		APP_voidChangePasswordScreen();
	}

	/* User choice is unknown , so get back to welcome screen */
	else
	{
		/* display : -
		 * "Wrong Input"
		 * "System reset"
		 */
		LCD_clearScreen();
		LCD_displayString("Wrong Input");
		LCD_moveCursor(1, 0);
		LCD_displayString("System reset");
		_delay_ms(LONG_DELAY);

		/* Move to the welcome screen */
		APP_voidWelcomeScreen();
	}
}

/******************************************************/
/******A function to make open safe operations*********/
static void APP_voidOpenSafeScreen(){
	uint8 userEnteredPassword[4];
	password_State state = WRONG_PASSWORD;
	for(uint8 i =0;i<3 && state ==WRONG_PASSWORD  ;i++)
	{
		/* display enter password */
		LCD_clearScreen();
		LCD_displayString("Enter Password");
		LCD_moveCursor(1, 0);

		/* Get the password */
		for(uint8 j=0;j<4;j++)
		{
			userEnteredPassword[j] = KEYPAD_getPressedKey();
			_delay_ms(SHORT_DELAY);
			LCD_displayCharacter('*');
		}

		state = TRUE_PASSWORD;
		/* Check Password */
		for(uint8 j=0;j<4;j++)
		{
			if(userEnteredPassword[j] != g_password[j])
			{
				APP_voidWrongPasswordScreen(3-i);
				state = WRONG_PASSWORD;
				break;
			}
		}

	}
	if(state == TRUE_PASSWORD){
		APP_voidTruePasswordScreen();
		APP_voidMainMenuScreen();
	}
	else{
		APP_voidThiefAlert();
		APP_voidMainMenuScreen();
	}
}

/************************************************************/
/******A function to make change password operations*********/
static void APP_voidChangePasswordScreen(){
	uint8 userEnteredPassword[4];
	password_State state = WRONG_PASSWORD;
	for(uint8 i =0;i<3 && state ==WRONG_PASSWORD ;i++)
	{
		/* display enter password */
		LCD_clearScreen();
		LCD_displayString("Enter old Pass");
		LCD_moveCursor(1, 0);

		/* Get the password */
		for(uint8 j=0;j<4;j++)
		{
			userEnteredPassword[j] = KEYPAD_getPressedKey();
			_delay_ms(SHORT_DELAY);
			LCD_displayCharacter('*');
		}

		state = TRUE_PASSWORD;
		/* Check Password */
		for(uint8 j=0;j<4;j++)
		{
			if(userEnteredPassword[j] != g_password[j])
			{
				APP_voidWrongPasswordScreen(3-i);
				state = WRONG_PASSWORD;
				break;
			}
		}
	}
	if(state == TRUE_PASSWORD){
		APP_voidChangePassword();
		APP_voidMainMenuScreen();
	}
	else{
		APP_voidThiefAlert();
		APP_voidMainMenuScreen();
	}
}

/*********************************************************************/
/******A function to get the password from user and change it*********/
static void APP_voidChangePassword(){



	/* display enter password */
	LCD_clearScreen();
	LCD_displayString("Enter new Pass");
	LCD_moveCursor(1, 0);

	/* Get the password */
	for(uint8 j=0;j<4;j++)
	{
		g_password[j] = KEYPAD_getPressedKey();
		_delay_ms(3000);
		LCD_displayCharacter('*');
	}

	/* display : -
	 * "Password Updated"
	 * "Successfully"
	 */
	LCD_clearScreen();
	LCD_displayString("Password Updated");
	LCD_moveCursor(1, 0);
	LCD_displayString("Successfully!!");
	_delay_ms(SHORT_DELAY);

}

/******************************************************************/
/********A function to display wrong password + Tries left*********/
static void APP_voidWrongPasswordScreen(uint8 illetrations){

	/* display : -
	 * "Wrong password !!"
	 * "tries left {illetrations}"
	 */
	LCD_clearScreen();

	LCD_displayString("Wrong password !!");
	LCD_moveCursor(1, 0);
	LCD_displayString("Tries left ");
	LCD_integerToString(illetrations);

	/*
	 * Turn the red led on for 3 seconds
	 */
	RED_LED_on();

	_delay_ms(SHORT_DELAY);

	/*
	 * Turn the red led off
	 */
	RED_LED_off();
}

/****************************************************************************/
/********A function to Alert due to reaching the max number of tries*********/
static void APP_voidThiefAlert(){

	/* display : -
	 * "Wrong password !!"
	 */
	LCD_clearScreen();
	LCD_displayString("Thief Alert !!");

	/*
	 * Turn the red led on for 5 seconds
	 */
	RED_LED_on();
	_delay_ms(5000);
	/*
	 * Turn the red led off
	 */
	RED_LED_off();

	/* get back to the welcome screen*/
	APP_voidWelcomeScreen();
}

/*****************************************************/
/********A function to display True password *********/
static void APP_voidTruePasswordScreen(){

	/* display : -
	 * "True password !!"
	 */
	LCD_clearScreen();
	LCD_displayString("True password !!");
	LCD_moveCursor(1, 0);

	/*
	 * Turn the green led on for 5 seconds
	 */
	GRN_LED_on();
	_delay_ms(LONG_DELAY);

	/*
	 * Turn the green led off
	 */
	GRN_LED_off();
}
