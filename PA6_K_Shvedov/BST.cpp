//#include "BST.h"
//
///*
//* Programmer: Konstantin Shvedov
//* Class: CptS 122
//* Programming Assignment: PA6
//* Date: 25/10/2017
//* Description: This is the file with all BST functions
//*/
//
////constructor
//BST::BST()
//{
//	mpRoot = nullptr;
//}
////destructor
//BST::~BST()
//{
//	cout << endl << "Inside BST's destructor! Freeing each BSTNode in the BST!" << endl;
//	destroyBST();
//	cout << "Target OBLITERATED" << endl;
//}
//
////returns the root
//BSTNode *& BST::getRootPtr()
//{
//	return mpRoot;
//}
//
////sets the root
//void BST::setRootPtr(BSTNode *const pNewRoot)
//{
//	mpRoot = pNewRoot;
//}
//
////runs the translator program
//void BST::runTranslator()
//{
//	white();
//	//blue();
//	this->makeTree();
//	cout << "In Order Traversal Print" << endl;
//	inOrderTraversal(this->getRootPtr());
//	cout << endl;
//	this->printFile();
//	cout << endl;
//	this->translate();
//}
//
////prints file content to screen
//void BST::printFile()
//{
//	char symb = '\0';
//	ifstream file;
//	file.open("Convert.txt");
//	cout << "File content:" << endl;
//	if (file.is_open())
//	{
//		//cout << "File opened correctly" << endl;
//		while (!file.eof())
//		{
//			file >> noskipws >> symb;
//			if (symb != '\0')
//			{
//				cout << symb;
//			}
//		}
//		cout << endl;
//	}
//	else
//	{
//		cout << "There was an error reading file" << endl;
//	}
//	file.close();
//}
//
////translates the file to morse code and prints result to screen
//void BST::translate()
//{
//	char symb = '\0';
//	ifstream file;
//	file.open("Convert.txt");
//	cout << "Translation:" << endl;
//	//cout << endl << "File Opened for converting" << endl;
//	if (file.is_open())
//	{
//		//cout << "File opened correctly" << endl;
//		file >> noskipws >> symb;
//		while (!file.eof())
//		{
//			symb = toupper(symb);
//			if (symb == '\n')
//			{
//				cout << endl;
//			}
//			else if (symb == ' ')
//			{
//				cout << "   ";
//			}
//			else
//			{
//				cout << findSymb(this->getRootPtr(), symb) << " ";
//			}
//			file >> noskipws >> symb;
//		}
//		cout << endl;
//	}
//	else
//	{
//		cout << "There was an error reading file" << endl;
//	}
//	file.close();
//}
//
////checks if tree is empty
//bool BST::isEmpty()
//{
//	if (this->mpRoot == nullptr)
//	{
//		return true;
//	}
//	else return false;
//}
//
//void BST::inOrderTraversal(BSTNode *node)
//{
//	if (node == nullptr)
//	{
//		//Base case nothing to print
//	}
//	else
//	{
//		inOrderTraversal(node->getPLeft());
//		cout << *node << endl;
//		inOrderTraversal(node->getPRight());
//	}
//}
//
//void BST::preOrderTraversal(BSTNode *node)
//{
//	if (node == nullptr)
//	{
//		//Base case nothing to print
//	}
//	else
//	{
//		cout << node << endl;
//		inOrderTraversal(node->getPLeft());
//		inOrderTraversal(node->getPRight());
//	}
//}
//
//void BST::postOrderTraversal(BSTNode *node)
//{
//	if (node == nullptr)
//	{
//		//Base case nothing to print
//	}
//	else
//	{
//		inOrderTraversal(node->getPLeft());
//		inOrderTraversal(node->getPRight());
//		cout << node << endl;
//	}
//}
//
////inserts node
//void BST::insertNode(BSTNode *&node, BSTNode * const newBSTNode)
//{
//	if (node == nullptr)
//	{
//		node = newBSTNode;
//		//cout << node->getSymb() << "   " << node->getMorse() << endl;
//	}
//	else if (node->getSymb() < newBSTNode->getSymb())
//	{
//		insertNode(node->getPRight(), newBSTNode);
//	}
//	else if (node->getSymb() > newBSTNode->getSymb())
//	{
//		insertNode(node->getPLeft(), newBSTNode);
//	}
//	else
//	{
//		//identical node, no point in inserting
//	}
//}
//
////finds symbol in tree and returns morse code
//string BST::findSymb(BSTNode * const node, char symb)
//{
//	//cout << "inside find symbol" << endl;
//	if (node == nullptr)
//	{
//		return "NA";
//	}
//	else if (node->getSymb() == symb)
//	{
//		return node->getMorse();
//		//cout << "found symbol" << endl;
//	}
//	else if (node->getSymb() > symb)
//	{
//		//cout << "went left" << endl;
//		return findSymb(node->getPLeft(), symb);
//	}
//	else if (node->getSymb() < symb)
//	{
//		//cout << "went right" << endl;
//		return findSymb(node->getPRight(), symb);
//	}
//}
//
////makes the tree
//void BST::makeTree()
//{
////	int i = 0;
//	ifstream file;
//	file.open("MorseTable.txt");
////	cout << "Open File" << endl;
//	if (file.is_open())
//	{
//		BSTNode *newnode = new BSTNode();
//		file >> *newnode;
//		this->setRootPtr(newnode);
////		cout << "New Node Made Head" << endl;
//		while (!file.eof())
//		{
//			BSTNode *newBSTnode = new BSTNode();
//			file >> *newBSTnode;
//			insertNode(this->getRootPtr(), newBSTnode);
////			i++;
////			cout << "New Node Inserted: #" << i << endl;
//		}
//	}
//	else
//	{
//		cout << "There was an error reading file" << endl;
//	}
//	file.close();
////	cout << "File Closed" << endl;
//}
//
////destroys the tree
//void BST::destroyBST()
//{
//	destroyBSTHelper(mpRoot);
//}
////helper destructor for BST
//void BST::destroyBSTHelper(BSTNode * pMem)
//{
//	if (pMem != nullptr)
//	{
//		destroyBSTHelper(pMem->getPLeft());
//		destroyBSTHelper(pMem->getPRight());
//		delete pMem;
//		//out << "Deleted A Node" << endl;
//	}
//}