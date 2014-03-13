/*
 * File: DataStructure.h"
 */
#include<string>

using namespace std;

class DataStructure{
	public:
		DataStructure();
		~DataStructure();
		void insert(int);
		void print();
		void move(int, int);
		void remove(int, int);
		bool add(int, int, int);
		string isAlternating();


	private:
		int count;
		// cellT means cell type
		struct cellT{
			int value;
			cellT* link;
		};
		cellT* head;
		cellT* end;
		int getLength();
		cellT* traverseTo(int);
		bool isEmpty();

};
