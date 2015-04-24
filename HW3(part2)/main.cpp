// Yürek, Engin
// 040100524
// Programming Assignment 3 Part 2

#include<iostream>
#include<string>
#include<iostream>
#include<fstream>
#include <sstream>
#include"Header.h"

using namespace std;

int main(){
	
	string readings[3] = {" "};	//substring of the lines will be stored in here
	string lines;	//lines will be stored here
	string sub;		//substrings will be stored temporarily
	string taskName;

	int priority;

	queue_link_list myQueue;

	ifstream infile;	
	infile.open("input2.txt"); //opens the povided file

	ofstream outFile;		 
	outFile.open("output2.txt");	//creates the output file

	while (infile.good()){

		getline(infile, lines);		//reads file line by line
		
		istringstream iss(lines, istringstream::in);
		
		int i = 0;
		while (iss >> sub)		//divide lines by spaces between the strings and puts them into readings string array
		{
			readings[i] = sub;
			i++;
		}
		if (readings[0] == "enqueue"){		
			priority = atoi(readings[1].c_str());	//converts priority from string to integer
			taskName = readings[2];
			myQueue.enqueue(taskName, priority);		//adds taskName and its priority to the queue
			//cout << readings[2]<<"--"<< myQueue.getFront()<<endl;		//checks the queue lists the tasks according to its priorities
		}
		else if (readings[0] == "dequeue" ){
			cout << myQueue.getFront() << endl; //shows the task that will be written into output file
			outFile << myQueue.getFront()<<endl;	//wites the tasks that will be dequeued into the output file
			myQueue.dequeue();			
		}
	}

	//close  our files
	infile.close();	
	outFile.close();

	//empty the queue
	myQueue.~queue_link_list();
		getchar();
		return 0;
	}
	
	
	
