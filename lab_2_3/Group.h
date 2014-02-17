#ifndef __GROUP_H_INCLUDED__
#define __GROUP_H_INCLUDED__

#include "Person.h"
#include<string>
#include<vector>

class Group{
	public:
		Group(string n);
		string GetName();
		int GetNumberOfMembers();
		string GetMemberName(int i);
		void AddMember(Person* p);
		void DeleteMember(Person* p);
		// for testing

	private:
		string name;
		vector<Person*> members;

};

#endif
