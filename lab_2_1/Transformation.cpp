#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;

int main() {
	
	int size_of_matrix;
	int cell_input;

	// create a class for the matrix
	Matrix matrix;

	// Get the user input for the size of the matrix
	cin >> size_of_matrix;
	matrix.SetSize(size_of_matrix);

	// For the row of N by N matrix
	for(int row = 0; row < size_of_matrix; row++){
	// 	For the column of the N by N matrix
		for(int column = 0; column < size_of_matrix; column++){
	// 		Get user input  to fill up the matrix
			cin >> cell_input;
			matrix.SetCell(row, column, cell_input);
		}
	}

	for(int row = 0; row < size_of_matrix; row++){
	// 	For the column of the N by N matrix
		for(int column = 0; column < size_of_matrix; column++){
	// 		Get user input  to fill up the matrix
			cout << matrix.GetCell(row, column) << endl;;
		}
	}
	// Get K the user input for the number of operations to occur
	//
	// For each of K
	// 	Get and store the string of the operator to be performed


	// For each of the command
	// 	void operate(string operation, string type);
	// 	eg Rotate 90
	//
	// For each row
	// 	for each column
	// 		print out the matrix
	return 0;

}
