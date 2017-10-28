//#include "BSTNode.h"
//
///*
//* Programmer: Konstantin Shvedov
//* Class: CptS 122
//* Programming Assignment: PA6
//* Date: 25/10/2017
//* Description: This is the file with all BSTNode functions
//*/
//
////BSTNode constructor
//BSTNode::BSTNode(char newLet, string newMorse)
//{
//	mSymb = newLet;
//	mMorse = newMorse;
//	mpRight = nullptr;
//	mpLeft = nullptr;
//}
//
////BSTNode detructor
//BSTNode::~BSTNode()
//{
//	//INSIDE THE MAGNIFICENT BSTNODE DESTRUCTOR
//}
//
////-------------------------------------------------------------------------------//
////------------------------------------GETTERS------------------------------------//
////-------------------------------------------------------------------------------//
////gets the letter stored withtin the BSTNode object
//char BSTNode::getSymb() const
//{
//	if (this == NULL)
//	{
//		cout << "NULL NODE ENCOUNTERED" << endl;
//	}
//	else return mSymb;
//}
////get the String of Morse code stored within the BSTNode object
//string BSTNode::getMorse() const
//{
//	if (this == NULL)
//	{
//		cout << "NULL NODE ENCOUNTERED" << endl;
//	}
//	else return mMorse;
//}
////getter for left pointer
//BSTNode *& BSTNode::getPLeft()
//{
//	if (this == NULL)
//	{
//		cout << "NULL NODE ENCOUNTERED" << endl;
//	}
//	else return mpLeft;
//}
////getter for right pointer
//BSTNode *& BSTNode::getPRight()
//{
//	if (this == NULL)
//	{
//		cout << "NULL NODE ENCOUNTERED" << endl;
//	}
//	else return mpRight;
//}
//
////-------------------------------------------------------------------------------//
////------------------------------------SETTERS------------------------------------//
////-------------------------------------------------------------------------------//
////sets the symbol to the new asighned one
//void BSTNode::setSymb(const char newSymb)
//{
//	this->mSymb = newSymb;
//}
////sets the Morse string to the new aighned one
//void BSTNode::setMorse(const string newMorse)
//{
//	this->mMorse = newMorse;
//}
////sets the left pointer to the new one
//void BSTNode::setPLeft(BSTNode *const newPLeft)
//{
//	this->mpLeft = newPLeft;
//}
////sets the right pointer to the new one
//void BSTNode::setPRight(BSTNode *const newPRight)
//{
//	this->mpRight = newPRight;
//}
//
////-------------------------------------------------------------------------------//
////-----------------------------------OVERLOADED----------------------------------//
////-------------------------------------------------------------------------------//
//ostream &operator << (ostream &lhs, BSTNode &rhs)
//{
//	lhs << rhs.getSymb() << "  " << rhs.getMorse();
//	return lhs;
//}
//ifstream &operator >> (ifstream &lhs, BSTNode &rhs)
//{
//	char symb;
//	string morse;
//
//	lhs >> symb;
//	rhs.setSymb(symb);
//	lhs >> morse;
//	rhs.setMorse(morse);
//	return lhs;
//}