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
			cout << cur->value << " ";
			cur = cur->next;
		}
	}
	cout << endl;
}

bool DataStructure::isEmpty() const{
	return (count == 0);
}

void DataStructure::remove(const int deleteItem){
	ListNode* current;
	int current_index = 0;

	bool found;

	if(head->value == deleteItem){
		current = head;
		head = head->next;
		if(head != NULL)
			head->prev = NULL;
		else
			tail = NULL;
		count--;
		delete current;
	}
	else{
		current = head;
		found = false;

		while(current != NULL && !found)
			if(current->value == deleteItem){
				found = true;
				break;
			}
			else
				current = current->next;

		// so now i have the pointer to the item to be deleted
		if(found == true){
			count--;
			ListNode* current_next_pointer = current->next;
			if(current_next_pointer != NULL){
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			else{
				current->prev->next = NULL;
				tail = current->prev;
			}
			
			delete current;


		}
	}
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
//		cout << "hi" << endl;
		current = head;
		found = false;

		while(current != NULL && !found){
			if(current->value >= deleteItem)
				found = true;
			else
				current = current->next;
		}

		if(current == NULL)
			cout << "1 The item to be deleted is not in the list" << endl;
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
		else{
			cout << "2 The item to be deleted is not in the list" << endl;
			cout << "the value is: " << current->value << endl;
		}
	}
}

bool DataStructure::search(const int &searchItem) const{
	ListNode* current = head;
	while(current != NULL){
		if (current->value == searchItem)
			return true;
		else
			current = current->next;
	}
	return false;
}

bool DataStructure::traverseTo(DataStructure::ListNode* searchNode, const int &searchValue) const{
	ListNode* current = head;
	while(current != NULL){
		if(current->value == searchValue){
			searchNode = current;
			return true;
		}
		else
			current = current->next;
	}

	return false;
}


bool DataStructure::getIndexFromValue(const int &value, int &index, DataStructure::ListNode* &index_pointer) const{
	int current_index = 1;
	ListNode* current = head;

	while(current != NULL){
		if(current->value == value){
			index = current_index;
			index_pointer = current;
//			cout << "value: " << index_pointer->value << " present at index: " << index << endl;
			return true;
		}
		else{
			current_index++;
			current = current->next;
		}
	}
	
	cout << "value: " << value << " not found" << endl;
	return false;
}

bool DataStructure::moveLeft(const int x_value, const int y_value){
	int x_pos;
	int y_pos;

	ListNode* x_pointer;
	ListNode* x_trail_pointer;
	ListNode* y_pointer;

	if(!getIndexFromValue(x_value, x_pos, x_pointer))
		return false;
	if(!getIndexFromValue(y_value, y_pos, y_pointer))
		return false;

//	cout << "x_pos: " << x_pos << endl;
//	cout << "x_pointer value: " << x_pointer->value << endl;
//	cout << "y_pointer value: " << y_pointer->value << endl;
	if(x_pos > y_pos){
		x_trail_pointer = x_pointer->prev;
		x_trail_pointer->next = x_pointer->next;
		if(x_pointer->next != NULL)
			x_pointer->next->prev = x_trail_pointer;
		else
			tail = x_trail_pointer;
		// if head points to y, head now points to x
//		cout << "in" << endl;
		if(head == y_pointer){
			head = x_pointer;
			x_pointer->prev = NULL;
		}
		else{
			y_pointer->prev->next = x_pointer;
			x_pointer->prev = y_pointer->prev;
		}

		y_pointer->prev = x_pointer;
		x_pointer->next = y_pointer;
		
		return true;
	}

	return false;
}

bool DataStructure::moveRight(const int x_value, const int y_value){
	int x_pos;
	int y_pos;

	ListNode* x_pointer;
	ListNode* y_pointer;
	ListNode* x_next_pointer;

	if(!getIndexFromValue(x_value, x_pos, x_pointer))
		return false;
	if(!getIndexFromValue(y_value, y_pos, y_pointer))
		return false;

	if(x_pos < y_pos){
		x_next_pointer = x_pointer->next;
		x_next_pointer->prev = x_pointer->prev;
		if(x_pointer->prev != NULL){
			x_pointer->prev->next = x_next_pointer;
		}
		else
			head = x_next_pointer;

		if(y_pointer->next != NULL){
			x_pointer->next = y_pointer->next;
			y_pointer->next->prev = x_pointer;
		}
		else{
			x_pointer->next = NULL;
			tail = x_pointer;
		}

		y_pointer->next = x_pointer;
		x_pointer->prev = y_pointer;

		return true;
	}
	return false;
	
}
