#include<iostream>
#include<string>
using namespace std;


// Identify which part of string a is in string b
// return -1 if not found
int CompareAndConcat(string a, string b){
	
	int pos = -1;
	string a_substring;

	cout << "COMPARING      " << a << "      AND       " << b << endl;

	for(int i = a.length(); i > 5  && pos == -1 ; i--){
		a_substring = a.substr(0, i);
		cout << "a_substring: " << a_substring << endl;
		pos = b.find(a_substring);
		cout << "pos: " << pos << endl;
	}

	if(pos == -1){
		string b_substring;
		for(int i = b.length(); i > 5  && pos == -1 ; i--){
			b_substring = b.substr(0, i);
			cout << "b_substring: " << b_substring << endl;
			pos = a.find(b_substring);
			cout << "pos: " << pos << endl;
		}
	}

	return pos;
}

string form(string s_1, string s_2, string s_3){
	string new_string;

	
	//form substrings
	string substring_1, substring_2, substring_3;
	
	int s_1_position, s_2_position, s_3_position = 0;


	cout << "s_1: " << s_1 << endl;
	cout << "s_2: " << s_2 << endl;
	cout << "s_3: " << s_3 << endl;


	int position;
	string s;

	position = CompareAndConcat(s_1, s_2);
	if (position > 0){

		substring_2 = s_2.substr(0, position) + s_1;
		cout << "substring_2: " << substring_2 << endl;
	}
	
	position = CompareAndConcat(s_1, s_3);
	if (position > 0){
		substring_3 = s_3.substr(0, position) + s_1;
		cout << "substring_3: " << substring_3 << endl;
	}

//	position = CompareAndConcat(s_2, s_1);
//	if (position > 0){
//		substring_1 = s_1.substr(0, position) + s_2;
//		cout << "substring_1: " << substring_1 << endl;
//	}

	position = CompareAndConcat(s_2, s_3);
	if (position > 0){
		substring_3 = s_3.substr(0, position) + s_2;
		cout << "substring_3: " << substring_3 << endl;
	}

//	position = CompareAndConcat(s_3, s_1);
//	if (position > 0){
//		substring_1 = s_1.substr(0, position) + s_3;
//		cout << "substring_1: " << substring_1 << endl;
//	}

//	position = CompareAndConcat(s_3, s_2);	
//	if (position > 0){
//		substring_2 = s_2.substr(0, position) + s_3;		
//		cout << "substring_2: " << substring_2 << endl;
//	}


	cout << "substring_1: " << substring_1 << endl;
	cout << "substring_2: " << substring_2 << endl;
	cout << "substring_3: " << substring_3 << endl;
	
	if(substring_1 == ""){
		CompareAndConcat(substring_2, substring_3);
	}


	int final = CompareAndConcat(substring_2, substring_3);
	cout << "final: " << s << endl;
	// compare string 1 and string 2


	return s;
}


int main(){
	
	string s_1, s_2, s_3;

	s_3 = "fox jumps over the lazy dog, while the five hexing wi";
	s_1 = ", while the five hexing wizard bots jump quickly";
	s_2 = "the quick brown fox jumps over the lazy d";

	form(s_1, s_2, s_3);


	return 0;

}
