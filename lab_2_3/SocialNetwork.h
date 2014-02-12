#ifndef __SOCIALNETWORK_H_INCLUDED__
#define __SOCIALNETWORK_H_INCLUDED__

#include "Group.h"
#include "Person.h"
#include<vector>
#include<string>

using namespace std;

class SocialNetwork{
	public:
		SocialNetwork();
		void GroupWithMostMembers();
		void PersonWithMostFriends();
		bool GroupDoesNotExist(string g);
		void AddGroup(string g);
		void PersonJoin(string g, string p);
		void PersonLeave(string g, string p);

		// Debug Purposes
		void PrintGroups();
		void PrintMembers();

	private:
		// I would implement  the data structure using the map class given the choice
		// But in the spirit of learning, the class vector is used
		vector<Person*> Persons;
		vector<Group*> Groups;
		Person* FindPerson(string p_name);
		Group* FindGroup(string g_name);
};
#endif
