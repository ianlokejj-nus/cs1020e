/*
 * File: Matrix.cpp
 * ----------------
 *  Implement the Matrix class
 */

#include<iostream>
#include<string>
#include "Matrix.h"

Matrix::Matrix(){
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

void Matrix::Operate(string operation){
	query = GetQuery(operation);
	format = GetFormat(operation);
	ProcessOperation(query, format);
}

void Matrix::SetNumberOfOperations(int size){
	number_of_operations = size;
}

void Matrix::ProcessOperation(string query, string format){
	if(query == "Rotate"){
		if(format == "90"){
			Rotate();
		}
		else if(format == "180"){
			Rotate();
			Rotate();
		}
		// format is 270
		else{
			Rotate();
			Rotate();
			Rotate();
		}
	}
	// query is Reflect
	else{
		if(format == "x"){
			ReflectX();			
		}
		// format is Y
		else{
			ReflectY();
		}
	}

}

void Matrix::ReflectX(){
	int tmp_matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];

	int i = matrix_size - 1;
	for(int row = 0; row < matrix_size; row++){
		for(int column = 0; column < matrix_size; column++){
			tmp_matrix[row][column] = matrix[i][column];
		}
		i--;
	}

	for(int row = 0; row < matrix_size; row++){
		for(int column = 0; column < matrix_size; column++){
			matrix[row][column] = tmp_matrix[row][column];
		}
	}	
}

void Matrix::ReflectY(){
	int tmp_matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];

	for(int row = 0; row < matrix_size; row++){

		int i = matrix_size - 1;
		for(int column = 0; column < matrix_size; column++){
			tmp_matrix[row][column] = matrix[row][i];
			i--;
		}
	}

	// Copy over the contents back to array
	for(int row = 0; row < matrix_size; row++){
		for(int column = 0; column < matrix_size; column++){
			matrix[row][column] = tmp_matrix[row][column];
		}
	}
}

void Matrix::Rotate(){
	int tmp_matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];

	for(int row = 0; row < matrix_size; row++){
		int i = matrix_size - 1;
		for(int column = 0; column < matrix_size; column++){
			tmp_matrix[row][column] = matrix[i][row];			
			i--;
		}
	}

	// Copy over contents back to array
	for(int row = 0; row < matrix_size; row++){
		for(int column = 0; column < matrix_size; column++){
			matrix[row][column] = tmp_matrix[row][column];
		}
	}	
}

string Matrix::GetQuery(string operation){
	string q;
	int pos;

	// Find the position of the space character
	pos = operation.find(" ");
	q = operation.substr(0, pos);
	return q;
}

string Matrix::GetFormat(string operation){
	string f;
	int pos;
	// Find the position of the space character
	pos = operation.find(" ");
	// Get string after the space character
	f = operation.substr(pos + 1);
	return f;
}	
