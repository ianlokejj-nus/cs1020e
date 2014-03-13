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
			ball_list.print();
		}
		else if(op == 'B'){
			cin >> y_value;
			ball_list.moveRight(x_value, y_value);
			ball_list.print();
		}
		else{
			ball_list.remove(x_value);
			ball_list.print();	
		}
	}

	ball_list.print();
	return 0;
}
