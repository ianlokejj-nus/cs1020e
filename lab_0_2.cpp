/*
 * File: lab_0_2.cpp
 * -----------------
 *
 *  The objective of this problem is to ensure that students know how to use 2 dimensional array and simple looping technique.
 *
 *  Given a 2 dimensional array of size N x M containing 1 or 0 and a query (ROW or COLUMN), determine the sum of the numbers in the array corresponding to the query. For example, query “ROW 3” means sum all the elements in the 3rd row of the array.
 *
 *  Input
 *  -----
 *  The first line of the input contains two integers, N (1 <= N <= 100) and M (1 <= M <= 100). The next line is an array with size N x M. The next line is the query with format “ROW x“, (1 <= x <= N) or “COLUMN y”, (1 <= y <= M).
 *
 * Output
 * ------
 * Output the answer to the query.
 */

#include<iostream>
#include<string>
using namespace std;

/* Function prototypes */
string RowOrColumn(string e);
int GetQueryNumber(string r,string q);

/* Main program */
int main(){

	int number_of_rows, number_of_columns;
	int matrix[100][100];
	string user_query;
	string res;

	// Get the 2 int input from users number_of_rows and number_of_columns
	cin >> number_of_rows >> number_of_columns;
	
	// Populate the number_of_rows by number_of_columns matrix
	// For each of the row,
	for(int row_number = 0; row_number < number_of_rows; row_number++){
		// User input the elements inside
		for( int column_number = 0; column_number < number_of_columns; column_number++){
			cin >>  matrix[row_number][column_number];
		}
	}
	
	cin.ignore();

	// Get the query from the user
	getline(cin, user_query);

	// Determine if the query is based on Column or Row
	res = RowOrColumn(user_query);

	int query_number;
	query_number = GetQueryNumber(res, user_query); 
	
	int sum;
	// Reduce query number by 1 to reference the element in the matrix
	query_number--;
	
	// Based on the user query, determine the sum of the elements 
	if(res == "ROW"){
		for(int column_number = 0; column_number < number_of_columns; column_number++){
			sum+=matrix[query_number][column_number];
		}
	}
	else{
		for(int row_number = 0; row_number < number_of_rows; row_number++){
			sum+=matrix[row_number][query_number];
		}	
	}
	
	cout << sum << endl;
	return 0;
}

/*
 * Function: RowOrColumn
 * ---------------------
 *  This function returns the string ROW or COLUMN based on the user input
 */
string RowOrColumn(string e){
	size_t found;
	string res;
	if((found = e.find("ROW")) != string::npos){
		res = "ROW";
	}
	else{
		res = "COLUMN";
	}

	return res;
}

/*
 * Function GetQueryNumber
 * -----------------------
 *  This function returns the query number which was given by the user
 */
int GetQueryNumber(string r,string q){
	if(r == "ROW"){
	//	Remove the ROW with space delimiter from string
		q.erase(0, 4);
	}
	else{
	//	Remove the COLUMN  with space delimiter from string
		q.erase(0, 7);
	}
	
	// Convert the query number from string to int
	int query_number;
	query_number = stoi(q);
	return query_number;	
}
