/*
 * File: Person.cpp
 */

#include "Person.h"
#include<iostream>
Person::Person(string n, int h, int w){
	name = n;
	height = h;
	weight = w;
}

Person* Person::tallest(vector<Person*> list) {
	// get the tallest person from a list of people
	return NULL;
}

Person* Person::shortest(vector<Person*> list) {
	// get the shortest person from a list of people
	return NULL;
}
double Person::GetBMI() {
	// compute the BMI by using the formula given 
	double height_in_m = height * 1.0 / 100; 
	bmi = weight / (height_in_m * height_in_m);
	return bmi;
}

int Person::GetHeight(){
	return height;
}

int  Person::GetWeight(){
	return weight;
}

string Person::GetName(){
	return name;
}
