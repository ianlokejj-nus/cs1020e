#include "Person.h"
#include "Group.h"
#include<vector>

Person::Person(string n){
	name = n;
}

string Person::GetName(){
	return name;
}

int Person::GetNumberOfFriends(){
	int total_number_of_friends = 0;
	vector<string> friends_list;
	for(int i = 0; i < GetNumberOfGroups(); i++){
		for(int j = 0; j < groups[i]->GetNumberOfMembers(); j++){
			if(groups[i]->GetMemberName(j) == name)
				continue;
			else{
				if(find(friends_list.begin(), friends_list.end(),  groups[i]->GetMemberName(j))== friends_list.end())
					friends_list.push_back(groups[i]->GetMemberName(j));
			}
		}
	}
	return friends_list.size();
}

int Person::GetNumberOfGroups(){
       return groups.size();
}

void Person::AddGroup(Group* g){
	groups.push_back(g);
}

void Person::DeleteGroup(Group* g){
	for(int i = 0; i < groups.size(); i++){
		if (groups[i]->GetName() == g->GetName()){
			groups.erase(groups.begin() + i);
			break;
		}
	}
}
