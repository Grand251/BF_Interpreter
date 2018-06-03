#include <algorithm>
#include<iostream>
#include "BFInterpreter.h"


BFInterpreter::BFInterpreter()
{
  reset();
}

void BFInterpreter::reset() {
	std::fill(memory, memory + MEMORY_SIZE, 0);
	memoryPtr = 0;
}


bool BFInterpreter::interpret(const std::string &src)
{	
	reset();
	if (!isBalanced(src))
		return false;

	int position = 0;

	while (position != (int) src.size()) {
		
		position = excecute(src, position);

		if (position == -1)
			return false;
	}


	return true;
}

//This will excecute the character as well as direct to the next character 
int BFInterpreter::excecute(const std::string &src, int position) {

	if (src[position] == '>') {
		incrementPtr();
		return position + 1;
	}
	
	if (src[position] == '<') {
		decrementPtr();
		return position + 1;
	}
	
	if (src[position] == '+') {
		incrementVal();
		return position + 1;
	}

	if (src[position] == '-') {
		decrementVal();
		return position + 1;
	}

	if (src[position] == ',') {
		inputChar();
		return position + 1;
	}

	if (src[position] == '.') {
		outputChar();
		return position + 1;
	}

	if (src[position] == '[')
		return enterLoop( src, position);

	if (src[position] == ']')
		return -1;


	//This is to assume any extraneous characters to be excluded
	return position + 1;
	

}


int BFInterpreter::enterLoop(const std::string &src, int position) {
	int oBrack = position;
	int cBrack;
	
	//Find closing corresponding closing bracket
	cBrack = findCBrack(src, position);

	//Begin with position after open bracket
	position++;

	//If while condition is fullfilled, direct to position after cBrack
	//if (*(memory + memoryPtr) == 0)
	//	return cBrack + 1;
	
	while (memory[memoryPtr] != 0) {
		
		while (position != cBrack) 
			position = excecute(src, position);

		position = oBrack + 1;
	}
	
	//return the next position after closing bracket
	return cBrack + 1;
}

// '>'
void BFInterpreter::incrementPtr() {
	memoryPtr++;
	if (memoryPtr == MEMORY_SIZE)
		memoryPtr = 0;

}

// '<'
void BFInterpreter::decrementPtr() {
	memoryPtr--;
	if (memoryPtr == -1)
		memoryPtr = MEMORY_SIZE -1;
}

// '+'
void BFInterpreter::incrementVal() {
	if (memory[memoryPtr] == 255)
		memory[memoryPtr] = 0;
	else
		memory[memoryPtr] = memory[memoryPtr] + 1;

}

// '-'
void BFInterpreter::decrementVal() {
	if (memory[memoryPtr] == 0)
		memory[memoryPtr] = 255;
	else
		memory[memoryPtr] = memory[memoryPtr] - 1;
}

// ','
void BFInterpreter::inputChar() {
	uint8_t c;
	std::cin >> c;
	memory[memoryPtr] = c;
}

// '.'
void BFInterpreter::outputChar() {
	std::cout << memory[memoryPtr];
}

//This traverses the source to make sure the brackets are balanced
bool BFInterpreter::isBalanced(const std::string &src) {
	
	std::string::const_iterator it = src.begin();
	
	int oBrack = 0;
	int cBrack = 0;
	
	while (it != src.end()) {
		if (*it == '[')
			oBrack++;
		if (*it == ']')
			cBrack++;

		it++;
	}

	return (oBrack == cBrack);
}

// Find the corresponding closing bracket
// The entering position should be that of the opening bracket
int BFInterpreter::findCBrack(const std::string &src, int position) {
	int numOBRack = 1;
	int numCBRack = 0;

	while (numOBRack != numCBRack) {
		position++;

		if (src[position] == '[')
			numOBRack++;
		if (src[position] == ']')
			numCBRack++;

	}
	
	//return position of corresponding bracket
	return position;
}










