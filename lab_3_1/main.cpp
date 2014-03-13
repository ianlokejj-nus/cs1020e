// Balls Objective
// The objective of this problem is to test the students’ understanding on Doubly Linked List.
// Problem Description
// There are N balls labelled with 1, 2, 3,..., N, from left to right. Now, we want to do two kinds of operations:
// 1. “A x y”: move the ball labelled x to the left of the ball labelled y, where x ≠ y. Reminder: if x is on the left of y, you may ignore this operation.
// 2. “B x y”: move the ball labelled x to the right of the ball labelled y, where x ≠ y. Reminder: if x is on the right of y, you may ignore this operation.
// 3. “R x”: remove the ball labelled x.
// Print the final arrangement after M operations.

// Input
// The first line contains two integers, N (1<= N <= 1,000) and M (1<= M <= 1,000). The next M lines contain the operations.
// Output
// Output the final arrangement of the N balls from left to right. Each number is followed by a whitespace.

#include<iostream>
#include "DataStructure.h"

using namespace std;

int main(){
	DataStructure ball_list;

	int number_of_balls;
	int number_of_operations;

	cin >> number_of_balls >> number_of_operations;

	for(int i = 1; i <= number_of_balls; i++){
		ball_list.insert(i);
	}

	char op;
	int x_value;
	int y_value;

	for(int i = 0; i < number_of_operations; i++){
		cin >> op >> x_value;
		if(op == 'A'){
			cin >> y_value;
			ball_list.moveLeft(x_value, y_value);
		//	ball_list.print();
		}
		else if(op == 'B'){
			cin >> y_value;
			ball_list.moveRight(x_value, y_value);
		//	ball_list.print();
		}
		else{
			ball_list.remove(x_value);
		//	ball_list.print();	
		}
	}

	ball_list.print();
	return 0;
}
