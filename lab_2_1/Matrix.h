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
#define MAX_MATRIX_SIZE 100;

class Matrix{
	public:
		Matrix();

		//~Matrix();

		void SetSize(int size);

		void SetCell(int row, int column, int cell_input);

		int GetCell(int row, int column);
	
	private:
		//#include "MatrixPriv.h"
		int matrix[100][100];	
		// TODO: create a pointer of double array
		//int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
		int matrix_size;
};

#endif
