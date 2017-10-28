/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA6
* Date: 25/10/2017
* Description: This is the main file. The program first reads morse code into a BST an dthe using that translates text from a file
*/

#include "BST.h"

int main(void)
{
	BST<char, string> run;
	run.runTranslator();
	return 0;
}