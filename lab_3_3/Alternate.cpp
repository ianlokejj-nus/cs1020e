/*
 * File: Alternate.cpp
 

Alternating List Objective
The objective of this problem is to test the students’ understanding on Singly Linked List. Problem Description
A list is alternating if its elements alternate between positive and negative.

You are given a linked list (original) and Q updates. For each update, check if the updated linked list is alternating. It is guaranteed that the elements in the linked list before and after update will not be 0.
There are 3 valid update operations, as explained below. Note that the indices of a list begin with one, not zero.
1. M <index> <size>: Move a block of elements of length <size> starting at index <index> to the back of the list. For example, let the current linked list be [1, 3, 5, 4, 2, 6]. The operation “M 2 3” moves [3, 5, 4] to the end of the linked list. The updated linked list is [1, 2, 6, 3, 5, 4].
2. R <index> <size>: Remove a block of elements of length <size> starting at index <index> from the linked list. For example, let the current linked list be [1, 3, 5, 4, 6, 7]. The operation “R 2 4” removes [3, 5, 4, 6] from the list. After performing the operation, we will have [1, 7].
3. A <index> <size> <value>: Add the elements between index <index> and <index + size – 1> (inclusive) with <value>. For example, let the current linked list be [1, -3, -5, 6, 10]. The operation “A 2 3 4” adds [-3, -5, 6] with value 4. The updated linked list is [1, 1, -1, 10, 10].
* It is guaranteed that <size> will not cause the index to go beyond the size of the Linked List (i.e. size + index – 1 LinkedList.size). For every operation, <size> is positive.
*/

#include<iostream>
#include "DataStructure.h"

using namespace std;

int main(){
	int expected_size_of_linked_list;
	int number_of_updates;

	cin >> expected_size_of_linked_list;
	cin >> number_of_updates;

	DataStructure a_list;
	int n;
	for(int i = 0; i < expected_size_of_linked_list; i++){
		cin >> n;
		a_list.insert(n);
			
	}

	// process the updates
	char update;
	int index;
	int size;
	int value;
	for(int i = 0; i < number_of_updates; i++){
		cin >> update;
		cin >> index >> size;
		// adjust the position of index
		if(update == 'M'){
			a_list.move(index, size);
			// a_list.print();
			cout << a_list.isAlternating() << endl;
		}
		else if (update == 'R'){
			a_list.remove(index, size);
			// a_list.print();
			cout << a_list.isAlternating() << endl;
		}
		// update is addition
		else{
			cin >>  value;
			a_list.add(index, size, value);
			// a_list.print();
			cout << a_list.isAlternating() << endl;
		}	
	}

	return 0;

}
