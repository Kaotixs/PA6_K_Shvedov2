#ifndef BSTNODE_H
#define BSTNODE_H

/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA6
* Date: 25/10/2017
* Description: This is the header file for BSTNode
*/

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::string;

template <class T, class R> class BST;

template <class T, class R>
class BSTNode
{
public:
	BSTNode(T newSymb, R newMorse);
	~BSTNode();
	
	T getSymb() const;
	R getMorse() const;
	BSTNode *&getPLeft();
	BSTNode *&getPRight();

	void setSymb(const T newSymb);
	void setMorse(const R newMorse);
	void setPLeft(BSTNode *const newPLeft);
	void setPRight(BSTNode *const newPRight);
	
private:
	T mSymb;
	R mMorse;
	BSTNode<T,R> *mpLeft;
	BSTNode<T,R> *mpRight;
};

//BSTNode Constructor
template <class T, class R>
BSTNode<T,R>::BSTNode(T newLet, R newMorse)
{
	mSymb = newLet;
	mMorse = newMorse;
	mpRight = nullptr;
	mpLeft = nullptr;
}

//BSTNode detructor
template <class T, class R>
BSTNode<T,R>::~BSTNode()
{
	//INSIDE THE MAGNIFICENT BSTNODE DESTRUCTOR
}

//-------------------------------------------------------------------------------//
//------------------------------------GETTERS------------------------------------//
//-------------------------------------------------------------------------------//
//gets the letter stored withtin the BSTNode object
template <class T, class R>
T BSTNode<T,R>::getSymb() const
{
	if (this == NULL)
	{
		cout << "NULL NODE ENCOUNTERED" << endl;
	}
	else return mSymb;
}
//get the String of Morse code stored within the BSTNode object
template <class T, class R>
R BSTNode<T,R>::getMorse() const
{
	if (this == NULL)
	{
		cout << "NULL NODE ENCOUNTERED" << endl;
	}
	else return mMorse;
}
//getter for left pointer
template <class T, class R>
BSTNode<T,R> *& BSTNode<T,R>::getPLeft()
{
	if (this == NULL)
	{
		cout << "NULL NODE ENCOUNTERED" << endl;
	}
	else return mpLeft;
}
//getter for right pointer
template <class T, class R>
BSTNode<T, R> *& BSTNode<T,R>::getPRight()
{
	if (this == NULL)
	{
		cout << "NULL NODE ENCOUNTERED" << endl;
	}
	else return mpRight;
}

//-------------------------------------------------------------------------------//
//------------------------------------SETTERS------------------------------------//
//-------------------------------------------------------------------------------//
//sets the symbol to the new asighned one
template <class T, class R>
void BSTNode<T,R>::setSymb(const T newSymb)
{
	this->mSymb = newSymb;
}
//sets the Morse string to the new aighned one
template <class T, class R>
void BSTNode<T,R>::setMorse(const R newMorse)
{
	this->mMorse = newMorse;
}
//sets the left pointer to the new one
template <class T, class R>
void BSTNode<T,R>::setPLeft(BSTNode *const newPLeft)
{
	this->mpLeft = newPLeft;
}
//sets the right pointer to the new one
template <class T, class R>
void BSTNode<T,R>::setPRight(BSTNode *const newPRight)
{
	this->mpRight = newPRight;
}

template <class T, class R>
ostream &operator << (ostream &lhs, BSTNode<T, R> &rhs)
{
	lhs << rhs.getSymb() << "  " << rhs.getMorse();
	return lhs;
}

template <class T, class R>
ifstream &operator >> (ifstream &lhs, BSTNode<T, R> &rhs)
{
	T symb;
	R morse;

	lhs >> symb;
	rhs.setSymb(symb);
	lhs >> morse;
	rhs.setMorse(morse);
	return lhs;
}

#endif