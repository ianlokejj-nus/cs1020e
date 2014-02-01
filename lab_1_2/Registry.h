/*
 * File: Registry.h
 */

#include<string>
#include<vector>
#include "Person.h"
using namespace std;

class Registry {

	public:
		Registry();
		void Add(Person P);
		void Print();
		Person* GetTallestPerson();
		Person* GetShortestPerson();

	private:
		vector<Person> list;

};
