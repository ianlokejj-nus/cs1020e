/*
 * File: Matrix.cpp
 * ----------------
 *  Implement the Matrix class
 */

#include<iostream>
#include<string>
#include "Matrix.h"

Matrix::Matrix(){
//	int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {};

}

void Matrix::SetSize(int size){
	matrix_size = size;
}

void Matrix::SetCell(int row, int column, int cell_input){
	matrix[row][column] = cell_input;
}

int Matrix::GetCell(int row, int column){
	return matrix[row][column];
}
