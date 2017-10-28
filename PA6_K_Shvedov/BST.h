#ifndef BST_H
#define BST_H

/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA6
* Date: 25/10/2017
* Description: This is the header file with all BST functions
*/

#include <iostream>
#include <fstream>
#include <string>

#include "BSTNode.h"
#include "gen_func.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::noskipws;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;


template <class T, class R>
class BST
{
public:
	//constructor
	BST();
	//destructor
	~BST();

	//getter
	BSTNode<T, R> *& getRootPtr(void);

	//setter
	void setRootPtr(BSTNode<T, R> *const pNewRoot);

	//runs the translator
	void runTranslator(void);

	//prints file content
	void printFile(void);

	//translate a string from file into morse
	void translate(void);

	//checks if the Tree is empty
	bool isEmpty(void);

	//prints the BST in order
	void inOrderTraversal(BSTNode<T,R> *node);
	void postOrderTraversal(BSTNode<T, R> *node); //dont really need it, but why not?
	void preOrderTraversal(BSTNode<T, R> *node);

	//inserting made node
	void insertNode(BSTNode<T, R> *&node, BSTNode<T, R> * const newBSTNode);

	//finds node
	R findSymb(BSTNode<T, R> * const, T symb);

	//make tree
	void makeTree(void);

private:
	BSTNode<T, R> *mpRoot;

	//detsructor for node
	void destroyBST(void);
	//helper destructor for BST
	void destroyBSTHelper(BSTNode<T, R> * const pMem);
};


//constructor
template <class T, class R>
BST<T, R>::BST()
{
	mpRoot = nullptr;
}
//destructor
template <class T, class R>
BST<T, R>::~BST()
{
	cout << endl << "Inside BST's destructor! Freeing each BSTNode in the BST!" << endl;
	destroyBST();
	cout << "Target OBLITERATED" << endl;
}

//returns the root
template <class T, class R>
BSTNode<T, R> *& BST<T, R>::getRootPtr()
{
	return mpRoot;
}

//sets the root
template <class T, class R>
void BST<T, R>::setRootPtr(BSTNode<T,R> *const pNewRoot)
{
	this->setRootPtr(pNewRoot);
}

//runs the translator program
template <class T, class R>
void BST<T, R>::runTranslator()
{
	white();
	//blue();
	this->makeTree();
	cout << "In Order Traversal Print" << endl;
	inOrderTraversal(this->getRootPtr());
	cout << endl;
	this->printFile();
	cout << endl;
	this->translate();
}

//prints file content to screen
template <class T, class R>
void BST<T, R>::printFile()
{
	T symb;
	ifstream file;
	file.open("Convert.txt");
	cout << "File content:" << endl;
	if (file.is_open())
	{
		//cout << "File opened correctly" << endl;
		while (!file.eof())
		{
			file >> noskipws >> symb;
			if (symb != '\0')
			{
				cout << symb;
			}
		}
		cout << endl;
	}
	else
	{
		cout << "There was an error reading file" << endl;
	}
	file.close();
}

//translates the file to morse code and prints result to screen
template <class T, class R>
void BST<T, R>::translate()
{
	T symb;
	ifstream file;
	file.open("Convert.txt");
	cout << "Translation:" << endl;
	//cout << endl << "File Opened for converting" << endl;
	if (file.is_open())
	{
		//cout << "File opened correctly" << endl;
		file >> noskipws >> symb;
		while (!file.eof())
		{
			symb = toupper(symb);
			if (symb == '\n')
			{
				cout << endl;
			}
			else if (symb == ' ')
			{
				cout << "   ";
			}
			else
			{
				cout << findSymb(this->getRootPtr(), symb) << " ";
			}
			file >> noskipws >> symb;
		}
		cout << endl;
	}
	else
	{
		cout << "There was an error reading file" << endl;
	}
	file.close();
}

//checks if tree is empty
template <class T, class R>
bool BST<T, R>::isEmpty()
{
	if (this->mpRoot == nullptr)
	{
		return true;
	}
	else return false;
}

template <class T, class R>
void BST<T, R>::inOrderTraversal(BSTNode<T, R> *node)
{
	if (node == nullptr)
	{
		//Base case nothing to print
	}
	else
	{
		inOrderTraversal(node->getPLeft());
		cout << *node << endl;
		inOrderTraversal(node->getPRight());
	}
}

template <class T, class R>
void BST<T, R>::preOrderTraversal(BSTNode<T, R> *node)
{
	if (node == nullptr)
	{
		//Base case nothing to print
	}
	else
	{
		cout << node << endl;
		inOrderTraversal(node->getPLeft());
		inOrderTraversal(node->getPRight());
	}
}

template <class T, class R>
void BST<T, R>::postOrderTraversal(BSTNode<T, R> *node)
{
	if (node == nullptr)
	{
		//Base case nothing to print
	}
	else
	{
		inOrderTraversal(node->getPLeft());
		inOrderTraversal(node->getPRight());
		cout << node << endl;
	}
}

//inserts node
template <class T, class R>
void BST<T, R>::insertNode(BSTNode<T, R> *&node, BSTNode<T, R> * const newBSTNode)
{
	if (node == nullptr)
	{
		node = newBSTNode;
		//cout << node->getSymb() << "   " << node->getMorse() << endl;
	}
	else if (node->getSymb() < newBSTNode->getSymb())
	{
		insertNode(node->getPRight(), newBSTNode);
	}
	else if (node->getSymb() > newBSTNode->getSymb())
	{
		insertNode(node->getPLeft(), newBSTNode);
	}
	else
	{
		//identical node, no point in inserting
	}
}

//finds symbol in tree and returns morse code
template <class T, class R>
R BST<T, R>::findSymb(BSTNode<T,R> * const node, T symb)
{
	//cout << "inside find symbol" << endl;
	if (node == nullptr)
	{
		return "NA";
	}
	else if (node->getSymb() == symb)
	{
		return node->getMorse();
		//cout << "found symbol" << endl;
	}
	else if (node->getSymb() > symb)
	{
		//cout << "went left" << endl;
		return findSymb(node->getPLeft(), symb);
	}
	else if (node->getSymb() < symb)
	{
		//cout << "went right" << endl;
		return findSymb(node->getPRight(), symb);
	}
}

//makes the tree
template <class T, class R>
void BST<T, R>::makeTree()
{
	//	int i = 0;
	ifstream file;
	file.open("MorseTable.txt");
	//	cout << "Open File" << endl;
	if (file.is_open())
	{
		BSTNode<T, R> *newnode = new BSTNode();
		file >> *newnode;
		this->setRootPtr(newnode);
		//		cout << "New Node Made Head" << endl;
		while (!file.eof())
		{
			BSTNode<T, R> *newBSTnode = new BSTNode();
			file >> *newBSTnode;
			insertNode(this->getRootPtr(), newBSTnode);
			//			i++;
			//			cout << "New Node Inserted: #" << i << endl;
		}
	}
	else
	{
		cout << "There was an error reading file" << endl;
	}
	file.close();
	//	cout << "File Closed" << endl;
}

//destroys the tree
template <class T, class R>
void BST<T, R>::destroyBST()
{
	destroyBSTHelper(mpRoot);
}
//helper destructor for BST
template <class T, class R>
void BST<T,R>::destroyBSTHelper(BSTNode<T,R> * pMem)
{
	if (pMem != nullptr)
	{
		destroyBSTHelper(pMem->getPLeft());
		destroyBSTHelper(pMem->getPRight());
		delete pMem;
		//out << "Deleted A Node" << endl;
	}
}

#endif