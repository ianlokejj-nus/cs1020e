/*
 * File: Matrix.h
 * --------------
 *  This file is the interface for a class that facilitates
 *  rotating a N by N matrix 
 *
 *  1. Rotate X
 *  -  Rotate the matrix by X degree, X can be 90, 180 or 270
 *     clockwise
 *
 *  2. Reflect x
 *  -  Reflect the matrix across the x axis
 *
 *  3. Reflect y
 *  -  Reflect the matrix across the y axis
 *
 */

#ifndef _Matrix_h
#define _Matrix_h
#define MAX_MATRIX_SIZE 100

using namespace std;

class Matrix{
	public:
		Matrix();

		void SetSize(int size);

		void SetCell(int row, int column, int cell_input);

		int GetCell(int row, int column);
	
		void SetNumberOfOperations(int op);

		void Operate(string operation);

	private:
		int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];	
		int matrix_size;
		int number_of_operations;
		string query;
		string format;

		string GetQuery(string operation);

		string GetFormat(string operation);
		
		void ProcessOperation(string query, string format);
		
		void Rotate();

		void ReflectX();

		void ReflectY();
};

#endif
