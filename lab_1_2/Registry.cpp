/*
 * File: Resgistry.cpp
 */

#include "Registry.h"
#include "Person.h"
#include<vector>

Registry::Registry(){

}

void Registry::Add(Person p){
	list.push_back(p);
}

void Registry::Print(){
	for(int i = 0; i < list.size(); i++){
		Person p = list[i];
		p.GetHeight();
	}
}


Person* Registry::GetTallestPerson(){
	Person* tallest_person = 0;
	int tallest_height;
	for(int p = 0; p < list.size(); p++){
		if(tallest_person == 0){
			tallest_person = &list[p];
			tallest_height = tallest_person->GetHeight();
			continue;
		}

		if(list[p].GetHeight() > tallest_height){
			tallest_person = &list[p];
			tallest_height = tallest_person->GetHeight();
		}
		else
			continue;

	}

	return tallest_person;
}

Person* Registry::GetShortestPerson(){
	Person* shortest_person = 0;
	int shortest_height;
	for(int p = 0; p < list.size(); p++){
		if(shortest_person == 0){
			shortest_person = &list[p];
			shortest_height = shortest_person->GetHeight();
			continue;
		}

		if(list[p].GetHeight() < shortest_height){
			shortest_person = &list[p];
			shortest_height = shortest_person->GetHeight();
		}
		else
			continue;
	}

	return shortest_person;
}
