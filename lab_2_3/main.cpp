/* File: main.cpp */

#include <iostream>
#include "SocialNetwork.h"

using namespace std;

int main(){

	SocialNetwork IanBook;
	int number_of_operations;
	int query_type;
	string group_name, person_name;
	cin >> number_of_operations;
	string command;
	for(int i = 0; i < number_of_operations; i++){
		cin >> command;
		if(command == "Query"){
			cin >> query_type;
			if(query_type == 1){

				IanBook.GroupWithMostMembers();
			}
			else
				IanBook.PersonWithMostFriends();
		}	
		else{
			cin >> person_name >> group_name;
			if(command == "Createjoin"){
				if (IanBook.GroupDoesNotExist(group_name)){
					IanBook.AddGroup(group_name);
				}
				IanBook.PersonJoin(group_name, person_name);
			}
			else
				IanBook.PersonLeave(group_name, person_name);
		}
	}
	//IanBook.PrintGroups();

	//IanBook.PrintMembers();
	return 0;
}


