// Yürek, Engin
// 040100524
// Programming Assignment 3 Part 1

#include<cstdlib>
#include<iostream>

#include"Header.h"

using namespace std;

//constructor
myStack::myStack(){		
	stackPtr = NULL;
}

//destructor
myStack::~myStack(){		
	
	while(stackPtr != NULL){
	
		Node* p = stackPtr;
		stackPtr = stackPtr->prev;
		p->prev = NULL;
		delete p;
	}

}

//adds new item into stack
void myStack::push(string addData){			
	Node * n = new Node();
	n->data = addData;

	if (stackPtr == NULL)				//works when stack is empty
	{
		stackPtr = n;
		stackPtr->prev = NULL;
		stackPtr->next = NULL;
	}
	else
	{
		stackPtr->next = n;
		n->prev = stackPtr;
		n->next = NULL;
		stackPtr = n;
	}

}

//reads the top of the stack
void myStack::readItem(Node* r){
	cout << "name:  " << r->data << endl;	
}

//deletes the top item of the stack
void myStack::pop(){

	if (stackPtr == NULL){
		cout << "There is nothing on the stack\n";
	}
	else
	{
		Node* p = stackPtr;
		stackPtr = stackPtr->prev;
		p->prev = NULL;
		delete p;
	}
}

//prints all items in stack
void myStack::printStack(){
	Node* p = stackPtr;
	while (p != NULL)
	{
		readItem(p);
		p = p->prev;
	}
}

//gives the data of the top item on stack
string myStack::get(){
	return stackPtr->data;
}

//checks if the stack is empty or not
bool myStack::isEmpty(){

	if (stackPtr == NULL)
		return true;
	else
		return false;

}