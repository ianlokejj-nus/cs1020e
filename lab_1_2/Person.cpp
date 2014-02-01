#include "Person.h"
#include<iostream>
Person::Person(string n, int h, int w){
	name = n;
	height = h;
	weight = w;;
}

Person* Person::tallest(vector<Person*> list) {
	// get the tallest person from a list of people
	return NULL;
}

Person* Person::shortest(vector<Person*> list) {
	// get the shortest person from a list of people
	return NULL;
}
double Person::getBMI() {
	// compute the BMI by using the formula given 
	return 0.0;
}

void Person::GetHeight(){
	cout << height << endl;
}
