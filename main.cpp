#include <iostream>
#include <fstream>
#include "BFInterpreter.cpp"

using namespace std;
void printHelp();

int main(int argc, char** argv) {
	
	string srcFileName;
	
	if (argc > 2) {
		cout << "Too many operands! Use -h for help!" << endl;
		return 0;
	}
	
	if (argc == 2) {
		
		string argument = argv[1];
		if (argument == "-h") {
			printHelp();
			return 0;
		}
		srcFileName = argument;
	}
	if (argc == 1) {
		cout << endl 
			<<  "Welcome to brainf*ck interpreter!" << endl
			<<"Enter source file path: ";
	
		cin >> srcFileName;
	}
	
	//Interpreter
	BFInterpreter bf;
	
	ifstream srcFile;
	srcFile.open(srcFileName, fstream::in);
	if (!srcFile.is_open()) {
		cout << "Source file could not be opened!" << endl;
		return 0;
	}
	string src = "";
	string temp;
	
	srcFile >> src;
	srcFile.close();

	bf.interpret(src);

	return 0;	
}

void printHelp() {
	cout << "Brainfuck Interpreter Help Menu" << endl
		<< "The program can be run with no arguments or the source file may be listed" << endl
		<< " as the first argument." << endl;
}





