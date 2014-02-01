/*
 * File: Measurement.cpp
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include "Person.h"
#include "Registry.h"
#include<iomanip>
using namespace std;

int main() {
	int number_of_persons;
	//vector<Person> persons_registry;
	//GOAL 1: store all the Person in the vector list
	
	// Read input for number of Person
	cin >> number_of_persons;

	Registry persons_registry;
	string name;
	int weight;
	int height;

	for(int p = 0; p < number_of_persons; p++){
		cin >> name >> height >> weight;

		persons_registry.Add(Person(name, height, weight));
		persons_registry.Print();
	}

	Person *tallest_person, *shortest_person;
	double tallest_person_bmi, shortest_person_bmi;

	tallest_person = persons_registry.GetTallestPerson();
	tallest_person_bmi = tallest_person->GetBMI();
	int a = tallest_person->GetHeight();
	shortest_person = persons_registry.GetShortestPerson();
	shortest_person_bmi = shortest_person->GetBMI();

	cout <<fixed;

	cout << shortest_person->GetName() << " is the shortest with BMI equals to " << setprecision(2) << shortest_person_bmi << "."  <<endl;

	cout << tallest_person->GetName() << " is the tallest with BMI equals to " << setprecision(2) << tallest_person_bmi << "." <<endl;
	return 0;
}
