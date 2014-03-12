#include<iostream>
#include "DataStructure.h"

using namespace std;

int main(){
	DataStructure ball_list;

	int number_of_balls;

	cin >> number_of_balls;

	for(int i = 1; i <= number_of_balls; i++){
		ball_list.insert(i);
	}

	ball_list.print();

	ball_list.deleteNode(4);

	ball_list.print();

	return 0;
}
