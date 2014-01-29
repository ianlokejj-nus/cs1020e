/*  File: lab_0_3.cpp
	-----------------
	Given 2 strings of the same size, determine which string is lexicographically smaller.
	User can assume that the letter's case does not matter

	Output
	------
	0 if string1 equals string2
	1 if string1 is lexicographically smaller than string2
	2 if string2 is lexicographically smaller than string1
	The strings contain only uppercase and lowercase Latin letters
 */

#include<iostream>
#include<string>

using namespace std;

/* Function prototypes*/
string ToLowerCase(string s);
int CompareLexi(string s_1, string s_2);

/* Main program */
int main(){
	string string_1, string_2;
	// Get First input string from user
	getline(cin, string_1);
	// Get Second input string from user
	getline(cin, string_2);

	// Convert string one to lowercase
	string_1 = ToLowerCase(string_1);
	// convert string two to lower case
	string_2 = ToLowerCase(string_2);
	
	int res;
	res = CompareLexi(string_1, string_2);
	cout << res << endl;

	return 0;
}

/*
	Function: ToLowerCase
	---------------------
	Converts a string to its lowercase equivalent
*/
string ToLowerCase(string s){
	for(int i = 0; i < s.length(); i++){
		s[i] = tolower(s[i]);
	}
	return s;
}

/*
	Function CompareLexi 
	--------------------
	Compares 2 strings lexicographically
*/
int CompareLexi(string s_1, string s_2){
	// Both strings are the same
	if (s_1 == s_2)
		return 0;
	else if	(s_1 < s_2)
		return 1;
	else
		return 2;
}	
