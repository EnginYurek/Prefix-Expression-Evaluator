// Yürek, Engin
// 040100524
// Programming Assignment 3  Part 2


#include<iostream>
#include "Header.h"

using namespace std;

//constructor
queue_link_list::queue_link_list(){
		frontPtr = NULL;
		backPtr= NULL;
}

//destructor
queue_link_list::~queue_link_list(){
	Node *p;
	while (frontPtr){
		p = frontPtr;
		frontPtr = frontPtr->nextPtr;
		delete p;
	}
}

//puts the nodes into the queue according to their priorities
void queue_link_list::enqueue(string addData, int addPriority){
	Node *newNode = new Node;
	Node *tempPrev=NULL;
	Node *tempNext= frontPtr;

	//definition of the node that will be added into queue
	newNode->nextPtr = NULL;
	newNode->taskName = addData;
	newNode->priority = addPriority;

	if (isEmpty()){			//for empty queue
		backPtr = newNode;
		frontPtr = backPtr;
	}
	else if (newNode->priority > frontPtr->priority){	//adds the new node to the head of the queue
		newNode->nextPtr = frontPtr;
		frontPtr = newNode;
	}
	else if (newNode->priority < frontPtr->priority){	//adds the new node to the very back of the queue
		backPtr->nextPtr = newNode;
		backPtr = newNode;
	}else	//add the newNode somewhere between the head and back of the queue
	{				
		while (tempNext->priority > newNode->priority){		//finds the appropriate place of the new node according to its priority
			tempPrev = tempNext;
			tempNext = tempNext->nextPtr;
		}
		tempPrev->nextPtr = newNode;
		newNode->nextPtr = tempNext;
	}
}

//deletes the front of the que
void queue_link_list::dequeue(){
	Node *delPtr;
	if (frontPtr != NULL){			//deletes while the queue is not empty
		delPtr = frontPtr;
		frontPtr = frontPtr->nextPtr;
		delete delPtr;
	}
}

//returns the taskName of head 
string queue_link_list:: getFront(){
	if (frontPtr != NULL)
		return frontPtr->taskName;
	else
		return "";
}

//checks if queue is empty or not
bool queue_link_list::isEmpty(){
	if (frontPtr == NULL)
		return true;
	else
		return false;

}

