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

void Matrix::Operate(string operation){

//	for(int op = 0; op < number_of_operations; op++){
//		ProcessOperation(operation)
//	}
	query = GetQuery(operation);
	format = GetFormat(operation);
	//ProcessOperation(query, format);
}

void Matrix::SetNumberOfOperations(int size){
	number_of_operations = size;
}

void ProcessOperation(string query, string format){
	
}

string Matrix::GetQuery(string operation){
	cout << "GetQuery" << endl;
	string q;
	int pos;

	// Find the position of the space character
	pos = operation.find(" ");
	cout << "pos: " << pos << endl;
	q = operation.substr(0, pos);
	cout << "q: " << q << endl;
	return q;
}

string Matrix::GetFormat(string operation){
	cout << "GetFormat" << endl;
	string f;
	int pos;
	// Find the position of the space character
	pos = operation.find(" ");
	cout << "pos: " << pos << endl;
	// Get string after the space character
	f = operation.substr(pos + 1);
	cout << "f: " << f << endl;
	return f;
}	
