#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
	
	int size_of_matrix;
	int cell_input;

	// Create a class for the matrix
	Matrix matrix;

	// Get the user input for the size of the matrix
	cin >> size_of_matrix;
	matrix.SetSize(size_of_matrix);

	// For the row of N by N matrix
	for(int row = 0; row < size_of_matrix; row++){
		// For the column of the N by N matrix
		for(int column = 0; column < size_of_matrix; column++){
			// Get user input  to fill up the matrix
			cin >> cell_input;
			matrix.SetCell(row, column, cell_input);
		}
	}

	int number_of_operations;
	string opn;

	// Get the user input for the number of operations to occur
	cin >> number_of_operations;
	matrix.SetNumberOfOperations(number_of_operations);

	cin.ignore();

	// For each operation
	for(int op = 0; op < number_of_operations; op++){
		// Get the contents of the operation
		getline(cin, opn);
		// Perform the operation
		matrix.Operate(opn);

	}

	// Print out the matrix
	for(int row = 0; row < size_of_matrix; row++){
		for(int column = 0; column < size_of_matrix; column++){
			cout << matrix.GetCell(row, column);
			// Do not print space for the last element
			if(size_of_matrix - 1 != column)
				cout << " ";
	}
		cout << endl;
	}

	return 0;

}
