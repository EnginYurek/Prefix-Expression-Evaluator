// Yürek, Engin
// 040100524
// Programming Assignment 3 Part 1


#include<string>
#include<iostream>
using namespace std;

struct node{

	string data;
	struct node *prev;
	struct node *next;
};

typedef struct node Node;

class myStack{
	
private:
	Node *stackPtr;
public:
	string get();
	myStack();
	~myStack();
	void push(string addData);
	void pop();
	bool isEmpty();
	void printStack();
	void readItem(Node *r);
};