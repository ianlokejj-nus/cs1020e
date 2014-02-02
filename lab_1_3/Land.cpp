/*
 * File: Land.cpp
 */

#include<iostream>
#define TREE_NOT_PRESENT 0
#define TREE_PRESENT 1

using namespace std;

int GetMaxLength(int grid[][80], int size_of_grid);
int GellCellMaxLength(int row, int column, int grid[][80], int size_of_grid); 	
int main(){
	int grid[80][80] = {0};
	// Get the size of the grid
	int size_of_grid;
	cin >> size_of_grid;

	// Get number of trees
	int trees;
	cin >> trees;

	// Location of trees
	int cord_1, cord_2;
	for(int i = 0; i < trees; i++){
		cin >> cord_1 >> cord_2;
		grid[cord_1-1][cord_2-1] = 1;
	}

	int max_length_for_house = GetMaxLength(grid, size_of_grid);

	cout << max_length_for_house << endl;

	return 0;
}

int GetMaxLength(int grid[][80], int size_of_grid){
	
	int max = 0;
	int max_from_cell;

	for(int row = 0; row < size_of_grid; row++){
		for(int column = 0; column < size_of_grid; column++){
			if(grid[row][column] == TREE_NOT_PRESENT){
				max_from_cell = GellCellMaxLength(row, column, grid, size_of_grid); 	
				if(max_from_cell > max){
					max = max_from_cell;
				}
			}
			else
				continue;
		}
	}

	return max;
}

int GellCellMaxLength(int row, int column, int grid[][80], int size_of_grid){
	int cell_max_length = 1;
	
	while((cell_max_length + row <= size_of_grid) && (cell_max_length + column <= size_of_grid)){
		for(int r = row; r < cell_max_length + row; r++){
			for(int c = column; c < cell_max_length + column; c++){
				if(grid[r][c] == TREE_PRESENT){
					return cell_max_length - 1;
				}
				else
					continue;
			}
		}

		cell_max_length++;

	}

	return cell_max_length - 1;
}	
