/*
 * File: Measurement.cpp
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include "Person.h"

using namespace std;

int main() {
	int number_of_persons;
	vector<Person> list_of_persons;
	//GOAL 1: store all the Person in the vector list
	
	// Read input for number of Person
	cin >> number_of_persons;
	//cin.ignore();

//	vector<Person> list_of_persons(100);
	string name;
	int weight;
	int height;
//
	for(int p = 0; p < number_of_persons; p++){
		cout << "Person: " << p << endl;
		cin >> name >> height >> weight;

		cout << "name: " << name<<endl;
		cout << "height: " << height << endl;
		cout << "weight: " << weight << endl;
		Person x = Person(name, height, weight);
		list_of_persons.push_back(Person(name, height, weight));
//		cin.ignore();
	}
//		cin >> name >> height >> weight;
//		cout << "name: " << name<<endl;
//		cout << "height: " << height<< endl;
//		cin.ignore();
	//	list_of_persons.insert(Person(name, height, weight));
//		list_of_persons[p] = Person(name, height, weight);
//	cout<<"next" << endl;
//	}


//	for(int i = 0; i < number_of_persons; i++){
//		list_of_persons[i].GetHeight();
//	}
	Person ian = Person("ian", 170, 80);
	ian.GetHeight();
	ian.GetWeight();
	// read input, create a Person object for each person in the input, store in a 
	
	// data structure (can use vector, refer to http://www.cplusplus.com/reference/vector/vector/)
	
	// process the data accordingly
	
	// output
	
	return 0;
}
