#include "gen_func.h"
/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA6
* Date: 25/10/2017
* Description: This is file that helps with formatting things
*/

/*
Function: void white(void)
Date Created : 05/04/2017
Date Last Modified : 02/10/2017
Description : changes text color to white
Input parameters : NONE
Returns : NONE
Precondition : Call function
Postconditions : None
*/
void white(void)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
}

/*
Function: void blue(void)
Date Created : 05/04/2017
Date Last Modified : 02/10/2017
Description : changes text color to blue
Input parameters : NONE
Returns : NONE
Precondition : Call function
Postconditions : None
*/
void blue(void)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
}