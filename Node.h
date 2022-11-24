#pragma once
#include<iostream>
using namespace std;

class Node
{
public:
	Node();
	Node(Node*, Node*, const int&);


	void setData(const int&);
	void setNextNode(Node*);
	void setPrevNode(Node*);


	int getData();
	Node* getNextNode();
	Node* getPrevNode();

private:
	Node* prevNode;
	Node* nextNode;
	int data;
};


