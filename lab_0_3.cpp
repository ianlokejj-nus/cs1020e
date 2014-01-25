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
int GetLexiSum(string s);
string ToLowerCase(string s);

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

	// Get the lexicographical sum for the characters in each string
	int string_1_lexi_sum, string_2_lexi_sum;
	string_1_lexi_sum = GetLexiSum(string_1);
	string_2_lexi_sum = GetLexiSum(string_2);

	// Compare cases
	if (string_1_lexi_sum == string_2_lexi_sum)
		cout << 0 << endl;
	else if(string_1_lexi_sum < string_2_lexi_sum)
		cout << 1 << endl;
	else
		cout << 2 << endl;
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
	Function GetLexiSum
	-------------------
	Returns the lexi sum of all the characters in a string
*/
int GetLexiSum(string s){
	int sum = 0;
	for(int i = 0; i < s.length(); i++){
		sum += s[i];
	}
	return sum;
}
