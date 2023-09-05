/******************************************************************************
 *
 * Layer: Application Layer
 *
 * File Name: app.h
 *
 * Description: header file for the app
 *
 * Author: Mohamed Ezzat
 *
 * Created on: 05/09/2023
 *
 * Version : v1.0.1
 *
 *******************************************************************************/
#ifndef APP_H_
#define APP_H_



/*******************************************************************************
 *                                  DataTypes                                  *
 *******************************************************************************/

typedef enum{TRUE_PASSWORD,WRONG_PASSWORD}password_State;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LONG_DELAY  3000
#define SHORT_DELAY 1000

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/******************************************************/
/********A function to initialize the Application******/
void APP_voidInit();

/*****************************************************/
/********A function to display the 1st screen*********/
void APP_voidWelcomeScreen();


#endif /* APP_H_ */
