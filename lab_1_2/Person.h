/*
 * File: Persion.h
 */

#ifndef __PERSON_H_INCLUDED__
#define __PERSON_H_INCLUDED__

#include <string>
#include <vector>

using namespace std;

class Person {
	public:
		Person(string name, int height, int weight);
		Person* tallest(vector<Person*> list);
		Person* shortest(vector<Person*> list);
		double GetBMI();
		int GetHeight();
		string GetName();
			
	private:
		// Class variables

		// Instance variables
		string name;	
		int height;
		int weight;
		double bmi;

		int GetWeight();
};

#endif
