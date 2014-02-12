/* File: SocialNetwork.cpp */

#include "SocialNetwork.h"
#include "Group.h"
#include "Person.h"
#include<vector>
#include<iostream>
using namespace std;

SocialNetwork::SocialNetwork(){
}

Person* SocialNetwork::FindPerson(string p_name){
	Person* p = NULL;
	for(int i = 0; i < Persons.size(); i++){
		if (Persons[i]->GetName() == p_name){
			p = Persons[i];
			return p;
		}
	}

	return p;
}

void SocialNetwork::GroupWithMostMembers(){
	int max = -1;
	string max_group_name;
	for(int i = 0; i < Groups.size(); i++){
		if (Groups[i]->GetNumberOfMembers() >= max){
			if (Groups[i]->GetNumberOfMembers() == max){
				if(Groups[i]->GetName() < max_group_name){
					max_group_name = Groups[i]->GetName();
				}
			}
			else{
				max = Groups[i]->GetNumberOfMembers();
				max_group_name = Groups[i]->GetName();
			}
		}
	}

	cout << max_group_name << endl;;
}

void SocialNetwork::PersonWithMostFriends(){
	int max = -1;
	string max_person_name;
	for(int i = 0; i < Persons.size(); i++){
//		cout << Persons[i]->GetName() << " has " << Persons[i]->GetNumberOfFriends() << endl;
		if(Persons[i]->GetNumberOfFriends() >= max){
			if(Persons[i]->GetNumberOfFriends() == max){
//				cout << "Chall: " << Persons[i]->GetName() << " max_string: " << max_person_name << endl;
				if (Persons[i]->GetName() < max_person_name){
					max_person_name = Persons[i]->GetName();
				}
//				cout << "winner: " << max_person_name << endl;
			}
			else{
				max = Persons[i]->GetNumberOfFriends();
				max_person_name = Persons[i]->GetName();
//				cout << "uncontested: " << max_person_name << endl;
			}
//		cout << "current winner: " << max_person_name << endl;
		}

	}

	cout << max_person_name << endl;
//	cout << endl;
}

Group* SocialNetwork::FindGroup(string g_name){
	Group* g = NULL;

	for(int i = 0; i < Groups.size(); i++){
		if(Groups[i]->GetName() == g_name){
			g = Groups[i];
			return g;
		}
	}

	return g;
}

void SocialNetwork::PersonJoin(string g_name, string p_name){
	// Update the Persons vector
	Person* p = NULL;
	Group* g = NULL;

	p = FindPerson(p_name);
	g = FindGroup(g_name);

	if(p == NULL){
		p = new Person(p_name);
		Persons.push_back(p);
	}

	p->AddGroup(g);
	g->AddMember(p);
}

void SocialNetwork::PersonLeave(string g_name, string p_name){
	Person* p = 0;
	Group* g = 0;

	p = FindPerson(p_name);
	g = FindGroup(g_name);

	p->DeleteGroup(g);
	g->DeleteMember(p);
}

bool SocialNetwork::GroupDoesNotExist(string g){
	for(int i = 0; i < Groups.size(); i++){
		if(Groups[i]->GetName() == g)
			return false;
	}

	return true;
}

void SocialNetwork::AddGroup(string g_name){
	Group* g = new Group(g_name);
	Groups.push_back(g);
}

void SocialNetwork::PrintGroups(){
	for(int i = 0; i < Groups.size(); i++){
		cout << "Group: " <<  Groups[i]->GetName() << endl;
		cout << "Number of Members: " << Groups[i]->GetNumberOfMembers() << endl;
	}
}

void SocialNetwork::PrintMembers(){
	for(int i = 0; i < Persons.size(); i++){
		cout << "Persons: " << Persons[i]->GetName() << endl;
		cout << "Number of Groups: " << Persons[i]->GetNumberOfGroups() << endl;
		cout << "Number of Friends " << Persons[i]->GetNumberOfFriends() << endl;
	}
}
