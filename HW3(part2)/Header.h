// Yürek, Engin
// 040100524
// Programming Assignment 3 Part2

#include<cstdlib>
#include<string>
using namespace std;

struct node {
	int priority;
	string taskName;
	node *nextPtr;
};

typedef struct node Node;

class queue_link_list{
private:
	Node *frontPtr;
	Node *backPtr;
public:
	string getFront();
	queue_link_list();
	~queue_link_list();
	void enqueue(string addData, int addPriority);
	void dequeue();
	bool isEmpty(); //checks the emptiness of the queue
};