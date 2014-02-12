#include "Group.h"
#include "Person.h"
#include<vector>

Group::Group(string n){
	name = n;
}

string Group::GetName(){
	return name;
}

string Group::GetMemberName(int i){
	return members[i]->GetName();
}

int Group::GetNumberOfMembers(){
	return members.size();
}

void Group::AddMember(Person* p){
	members.push_back(p);
}

void Group::DeleteMember(Person* p){
	for(int i = 0; i < members.size(); i++){
		if(members[i]->GetName() == p->GetName()){
			members.erase(members.begin() + i);
			break;
		}
	}
}
