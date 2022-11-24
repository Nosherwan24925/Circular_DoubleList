#pragma once
#include"Node.h"
class CircularDoublyList
{
public:
	CircularDoublyList();
	~CircularDoublyList();

	void insertAtStart(const int&);
	void insertAtEnd(const int&);
	void insertAtAnyNode(const int&, const int&);
	
	bool SearchValue(const int&);

	void deleteAtStart(void);
	void deleteBefore(const int&);
	void deleteAtEnd(void);
	void deleteAll(void);

	void displayList(void) const;

	int noOfNodes(void);

	void reverseList(void) const;
	int totalSum(void);
	void swapHeadAndTail(void);

	void removeDuplicates(void);

	void SortList(void);

	CircularDoublyList* shuffleMerger(CircularDoublyList*);

	CircularDoublyList* operator+(const CircularDoublyList&);


	Node* getHead(void);
	Node* getTail(void);



private:
	Node* head;
	Node* tail;
};

