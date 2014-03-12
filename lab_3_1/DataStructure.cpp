#include "DataStructure.h"

DataStructure::DataStructure(){
	head = NULL;
	tail = NULL;
	count = 0;
}

DataStructure::~DataStructure(){

}

void DataStructure::insert(const int insertItem){
	ListNode* current;
	ListNode* trailCurrent;
	ListNode* newNode;
	bool found;

	newNode = new ListNode;
	newNode->value = insertItem;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(head == NULL){
		head = newNode;
		tail = newNode;
		count++;
	}
	else{
		found = false;
		current = head;

		while(current != NULL && !found)
			// find the pos where current is greater than insertItem
			// NewNode will always be created infront of current
			// Except for the case where current is NULL (ie end of list)
			// In this case, I will insert it at the end
			if(current->value >= insertItem)
				found = true;
			else{
				trailCurrent = current;
				current = current->next;
			}
		//
		if(current == head){
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			count++;
		}
		else{
			// insert newNode between trailCurrent and current
			if(current != NULL){
				newNode->next = current;
				newNode->prev = trailCurrent;
				trailCurrent->next = newNode;
				current->prev = newNode;
			}
			// newNode will be placed at the end of the list
			else{
				newNode->prev = trailCurrent;
				trailCurrent->next = newNode;
				tail = newNode;
			}
			count++;
		}	
	}
}

void DataStructure::print() const{
	ListNode* cur = head;
	if(!isEmpty()){
		while(cur != NULL){
			cout << cur->value << endl;
			cur = cur->next;
		}
	}
}

bool DataStructure::isEmpty() const{
	return (count == 0);
}

void DataStructure::deleteNode(const int deleteItem){
	ListNode* current;
	ListNode* trailCurrent;

	bool found;

	if(head == NULL)
		cout << "Cannot delete from empty list" << endl;
	else if (head->value == deleteItem){
		current = head;
		head = head->next;
		
		if(head != NULL)
			head->prev = NULL;
		else
			tail = NULL;
		count--;

		delete current;
		current = NULL;
	}
	else{
		current = head;
		found = false;

		while(current != NULL && !found){
			if(current->value >= deleteItem)
				found = true;
			else
				current = current->next;
		}

		if(current == NULL)
			cout << "The item to be deleted is not in the list" << endl;
		else if(current->value == deleteItem){
			trailCurrent = current->prev;
			trailCurrent->next = current->next;

			if(current->next !=NULL)
				current->next->prev = trailCurrent;
			if(current == tail)
				tail = trailCurrent;

			count--;
		
			delete current;
			current = NULL;
		}
		else
			cout << "The item to be deleted is not in the list" << endl;
	}
}
