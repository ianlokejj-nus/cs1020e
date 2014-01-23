/*
 * File: lab_0_1.cpp
 * -----------------
 *
 * This problem is about simple arithmetic, given a binary operator (AND, OR) and two bits. Output the result of the operations.
 *
 * Type 1: The second line contains an integer N, indicating the number of operations. The next
 * N lines contain one string, denoting the operator and two bits denoting the operands.
 * 
 * Type 2: There are several lines containing the information of the given operations.
 * Each line contains one string, denoting the operator and two bits denoting the operands.
 * Read until special character ‘0’.
 * 
 * Type 3: There are several lines containing the information of the given operations. 
 * Each line contains one string, denoting the operator and two bits denoting the operands. Read until end of file.
 * 
 * There are at most 100 operations to be processed. This script will output the result of the operations.
 */

#include<iostream>
#include<string>
using namespace std;

/* Function prototypes */
bool ToBool(char c);
bool ProcessLine(string e);
bool ProcessBits(string bitwise_operator, bool operand_1, bool operand_2);

/* Main program */
int main(){

	int choice, N;
	// Enter choice (1,2,3)
	cin >> choice;

	if (choice == 1){
		bool results[101];
		// Read the number of integer N
		cin >> N;
		cin.ignore();

		string expression;	
		int result;
		int count = 0;
		for (int line_number = 0; line_number < N; line_number++){
			// Read line;
			getline(cin, expression);

			// Process line
			result = ProcessLine(expression);
			
			// Store the results in the results array
			results[count] = result;
			count++;
		}

		for( int r = 0; r < N; r++){
			cout << results[r] << endl;
		}
	}
	return 0;
}

/*
 * Function: ProcessLine
 * ---------------------
 *  This function takes a string from input and parses it.
 *  It returns the result of the binary operation. 
 */
bool ProcessLine(string e){
	int res;
	bool op[2];
	string bitwise_operator;
	int counter = 0;
	size_t found;

	// If the operator is AND
	if ((found = e.find("AND")) != string::npos){
		bitwise_operator = "AND";
		 // Remove operator together with space delimiter
		e.erase(0, 4);
		/// Process bits
		res = ProcessBits(bitwise_operator, ToBool(e[0]), ToBool(e[2]));
	}
	// if the operator is OR
	else if ((found = e.find("OR")) != string::npos){
		bitwise_operator = "OR";
		// Remove operator together with space delimiter
		e.erase(0, 3);
		// Process bits
		res = ProcessBits(bitwise_operator, ToBool(e[0]), ToBool(e[2]));
	}
	return res;
}

/*
 * Function: ToBool
 * -----------------
 *  This function converts the characters 0 and 1 to its boolean values
 */
bool ToBool(char c){
	return c != '0';
}

/*
 * Funtion: ProcessBits
 * ---------------------
 *  This function takes in the string format of the bitwise operator and 2 operands.
 *  The result of the binary operation is returned.
 */

bool ProcessBits(string bitwise_operator, bool operand_1, bool operand_2){
	bool result;
	if(bitwise_operator == "AND"){
		result = operand_1 & operand_2;
	}
	else
		result = operand_1 | operand_2;

	return result;
}

