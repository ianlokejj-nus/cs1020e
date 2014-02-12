#ifndef __PERSON_H_INCLUDED__
#define __PERSON_H_INCLUDED__

//#include "Group.h"
#include<string>
#include<vector>

using namespace std;

class Group;

class Person{
	public:
		Person(string n);
		string GetName();
//		string GetGroupName(int i);
		int GetNumberOfFriends();
		int GetNumberOfGroups();
		void AddGroup(Group* g);
		void DeleteGroup(Group* g);

	private:
		string name;
		vector<Group*> groups;
};

#endif

