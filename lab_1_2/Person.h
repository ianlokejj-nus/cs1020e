/*
 * File: Persion.h
 */

#include <string>
#include <vector>

using namespace std;

class Person {
	public:
		Person(string name, int height, int weight);
		Person* tallest(vector<Person*> list);
		Person* shortest(vector<Person*> list);
		double getBMI();
		void GetHeight();
		void GetWeight();
		//void AddToList(Person* p);
		//void SetHeight(int height);
		//void SetWeight(int weight);
		
	private:
		// Class variables
		//static vector<Person*> list;

		// Instance variables
		string name;	
		int height;
		int weight;
		
		//void GetHeight(Person* p);
		//void GetWeight(Person* p);	

};
