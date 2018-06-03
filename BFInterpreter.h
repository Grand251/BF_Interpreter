#ifndef BFInterpreter_H_
#define BFInterpreter_H_

#pragma once

#include <cstdint>
#include <string>
#include <sstream>


class BFInterpreter {
	public:
		static const int MEMORY_SIZE = 30000;

		BFInterpreter();

		/**
		Workhorse of BrainFuck interpreter.
		@param src A BrainFuck program source
		@return true if the source code is valid
		*/
		bool interpret(const std::string &src);

		//Reset the interpreter state.
		void reset();

		int ptr() const { return memoryPtr; }
	
	private:
  
		uint8_t memory[MEMORY_SIZE];
		int memoryPtr;
		
		void incrementPtr();
		void decrementPtr();
		void incrementVal();
		void decrementVal();
		void inputChar();
		void outputChar();
		bool isBalanced(const std::string &src);
		int findCBrack(const std::string &src, int postition);
		int enterLoop(const std::string &src, int position);
		int excecute( const std::string &src, int position);

};

#endif /* BF_H_ */
