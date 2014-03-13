/*
 * File: DataStructure.c"
 */
#include<iostream>
#include "DataStructure.h" 

DataStructure::DataStructure(){
	head = NULL;
	end = NULL;
	count = 0;
}

// TODO: implement delete
DataStructure::~DataStructure(){
	
}

void DataStructure::insert(int value){
	cellT *cell = new cellT;
	cell->value = value;
	cell->link = NULL;
	if(head == NULL){
		head = cell;
		end = cell;
	}	
	else{
		// go to the end and add the cell
		end->link = cell;
		end = cell;
	}
	count++;
}

// Debugging
void DataStructure::print(){
	cout << "printing" << count << endl;
	cellT* cursor = head;
	for(cursor = head; cursor != NULL; cursor = cursor->link){
		cout << cursor->value << " " ;	
	}
	cout << endl;
}

// Pre condition: User will supply an index and size which does not go out of range of the current list
// Post condition: Cells at position index to size will be moved to the end of the list 
void DataStructure::move(int index, int size){
	// it will not be the last element 
	int position_of_range = index + size - 1;
	if(position_of_range != count){

		cellT* cell_index = head;
		cellT* cell_range = head;
		cellT* cell_previous = head;

		// if index is in the front
		if(index == 1){
			for(int i = 1; i < position_of_range; i++){
				cell_range = cell_range->link;
			}
			for(int i = 1; i < index; i++){
				cell_index = cell_index->link;
			}
			head = cell_range->link;
			cell_range->link = NULL;
			end->link = cell_index;
			end = cell_range;
		}
		else{
			for(int i = 1; i < index; i++){
				cell_index = cell_index->link;
			}

			for(int i = 1; i < position_of_range; i++){
				cell_range = cell_range->link;
			}
			
			for(int i = 1; i < index - 1; i++){
				cell_previous = cell_previous->link;
			}
			
			cell_previous->link = cell_range->link;
			cell_range->link = NULL;
			end->link = cell_index;
			end = cell_range;

			//debugging
			// cout << cell_index->value << endl;
			// cout << cell_previous->value << endl;
			// cout << cell_range->value << endl;
		}

	}
}

// Pre condition: User will supply an index and size that does not exit the range of the current list
// Post condition: Cells from position index to its size will be removed from the current list
void DataStructure::remove(int index, int size){
	int position_of_range = index + size - 1;
	cellT* cell_index = head;
	cellT* cell_range = head;
	cellT* cell_previous = head;

	count -= size;

	for(int i = 1; i < index; i++){
		cell_index = cell_index->link;
	}

	for(int i = 1; i < position_of_range; i++){
		cell_range = cell_range->link;
	}
	// end will not change here because count must be >= 1
	if(index == 1){
		head = cell_range->link;
	}
	else{
		for(int i = 1; i < index - 1; i++){
			cell_previous = cell_previous->link;
		}
		if(cell_range->link == NULL){
			cell_previous->link = NULL;
			end = cell_previous;
		}
		else{
			cell_previous->link = cell_range->link;
			cell_range->link = NULL;
		}
	}

	// remove the cells
	cellT* old;
	for(int i = 0; i < size-1; i++){
		old = cell_index;
		cell_index = cell_index->link;
		delete old;
	}

}

//Pre condition: User will supply an index and size, indicating a value which they wish to add on top of the current value of the cells
// Post conditions: Cells at pos index to size will be updated to hold the values of the cells
bool DataStructure::add(int index, int size, int value){
	cellT* cell_index = head;
	for(int i = 1; i < index; i++){
		cell_index = cell_index->link;
	}
	for(int i = 0; i < size; i++){
		cell_index->value += value;
		cell_index = cell_index->link;
	}
	return true;
}

// Post condition: YES will be returned if values of the cell alternate between positive and negative (vice versa), else NO is returned
string DataStructure::isAlternating(){
	if(count == 0 || count == 1)
		return "YES";
	cellT* cell_index = head->link;
	cellT* cell_previous = head;
	for(int i = 0; i < count - 1; i++){
		if(cell_index->value * cell_previous->value > 0){
			return "NO";
		}
		cell_index = cell_index->link;
		cell_previous = cell_previous->link;
	}
	return "YES";
}



// Debugging functions
DataStructure::cellT* DataStructure::traverseTo(int index){
	if((index < 1) || (index > getLength()))
		return NULL; // return pointer if pre condition not met
	else{
		cellT* cur = head; // start from the head node
		for(int i = 1; i < index; i++){
			cur = cur->link;
		}
	return cur;
	}
}

int DataStructure::getLength() {
	return count;
}

bool DataStructure::isEmpty(){
	return (getLength() == 0);
}
