// Yürek, Engin
// 040100524
// Programming Assignment 3 Part 1

#include<cstdlib>
#include<string>
#include<iostream>
#include<fstream>
#include <sstream>
#include"Header.h"
using namespace std;

string performCalculation(string operand1, string operand2, string sub); //makes mathematical calculations
bool isOperator(string );		//checks the strings if they are operator or not
int main(){

	int i = 0;

	myStack line1;		//all operators and numbers will be pushed this stack object
	myStack prefixStack; //the operators and operand will be pushed here from line1 stack while the processing

	string sub;			// ý get all operatos and numbers separetely with sub string
	string STRING;		// ý get lines from the input1.txt and store them in STRING
	string operatr;		//denotes the operators
	string operand1;	//denotes the operands
	string operand2;

	ofstream outFile;		//creates the output file object
	outFile.open("output1.txt");	// creates output1.txt file
	ifstream infile;	// creates the input file object
	infile.open("input1.txt");	//opens our input file
	
	while (infile.good()) // To get all the lines.
	{
		getline(infile, STRING); // Saves the line in STRING.


		istringstream iss(STRING, istringstream::in); // seperates our STRING into the sub strings
		
		if (STRING == "\0" )  //there is a space character at the end of the file input1.txt(your original file) and it creates an empty substring
		continue;				// and this substring gives error while processing. that is why ý put this if statement
	
		while (iss >> sub)
		{
			line1.push(sub);		//push all strings to line1 stack object
		}
		while (!line1.isEmpty()){	//checks the emptiyness of the stack line1
			if (!isOperator(line1.get())) {		// checks the top of line1 stack is operator or number
				prefixStack.push(line1.get());		//pushes the operans to the prefixStack
				line1.pop(); 
			}
			else{
				operatr = line1.get();		//gets the operators as string
				line1.pop();

				operand1 = prefixStack.get();		//gets first operand as string
				prefixStack.pop();

				operand2 = prefixStack.get();		//gets second operand as string
				prefixStack.pop();
				
				prefixStack.push(performCalculation(operand1, operand2, operatr));
			}
			
		}
		outFile<< prefixStack.get()<<" ";	//writes the output of first line into the output1.txt file
		cout << prefixStack.get() << endl;	//prints output to the console	
		line1.~myStack();		//empties the stack line1
		prefixStack.~myStack();		//empties the stack line1
	}
	outFile.close();	//close output1.txt
	infile.close();		//close input1.txt
	
	getchar();
	return 0;
}

string performCalculation(string operand1, string operand2, string operatr){
	
	double op1, op2, result;
	
	op1 = atof(operand1.c_str());		//converts opernad 1 from string to double
	op2 = atof(operand2.c_str());		//converts opernad 1 from string to double

	ostringstream os;		

	//performs the operation between operand1 and operand2
	if (operatr == "+"){
		result = op1 + op2;
		os << result;		//converts result from double to string
		return os.str();
	}
	else if (operatr == "-"){
		result = op1 - op2;
		os << result;
		return os.str();
	}
	else if (operatr == "*"){
		result = op1*op2;
		os << result;
		return os.str();
	}
	else if (operatr == "/"){
		result = op1 / op2;
		os << result;
		return os.str();
	}
	
}
//checks the string is operator or not
bool isOperator(string sub){

	if (sub == "+" || sub == "-" || sub == "*" || sub == "/")
		return true;
	else
		return false;
}