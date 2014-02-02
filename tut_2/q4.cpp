#include<iostream>
#include<string>
#define MIN_STRING_SIZE 5

using namespace std;

string CompareAndConcat(string a, string b){
	
	int pos = -1;
	string a_substring;

	for(int i = a.length(); i > MIN_STRING_SIZE  && pos == -1 ; i--){
		a_substring = a.substr(0, i);
		pos = b.find(a_substring);
	}

	if(pos > 0)
		return b.substr(0, pos) + a;

	else{
		string b_substring;
		for(int i = b.length(); i > 5  && pos == -1 ; i--){
			b_substring = b.substr(0, i);
			pos = a.find(b_substring);
		}
	}

	if(pos > 0)
		return a.substr(0, pos) + b;
	else
		return "";

}

string form(string s_1, string s_2, string s_3){
	
	string substring_1, substring_2, substring_3;
	
	substring_1 = CompareAndConcat(s_1, s_2);
	substring_2 = CompareAndConcat(s_1, s_3);
	substring_3 = CompareAndConcat(s_2, s_3);

	string final;
	if(substring_1 == "")
		final = CompareAndConcat(substring_2, substring_3);
	else if( substring_2 == "")
		final = CompareAndConcat(substring_1, substring_3);
	else
		final = CompareAndConcat(substring_1, substring_2);

	return final;
}


int main(){
	
	string s_1, s_2, s_3;

	s_1 = "fox jumps over the lazy dog, while the five hexing wi";
	s_2 = ", while the five hexing wizard bots jump quickly";
	s_3 = "the quick brown fox jumps over the lazy d";

	cout << form(s_1, s_2, s_3) << endl;

	return 0;
}
