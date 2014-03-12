#include<iostream>

using namespace std;

class DataStructure{
	public:	
		DataStructure();
		~DataStructure();
		void insert(const int insertItem);
		void deleteNode(const int deleteItem);
		void print() const;
		bool isEmpty() const;
		bool search(const int &searchItem) const;
		//bool traverseTo(ListNode* searchNode, const int &searchValue) const;
	private:
		int count;
		struct ListNode{
			int value;
			ListNode* next;
			ListNode* prev;
		};
		ListNode* head;
		ListNode* tail;

		bool traverseTo(ListNode* searchNode, const int &searchValue) const;
};
