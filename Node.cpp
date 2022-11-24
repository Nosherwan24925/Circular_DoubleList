#pragma once
#include"Node.h"


Node::Node()
{
	nextNode = nullptr;
	prevNode = nullptr;
	data = 0;
}
Node::Node(Node* prev, Node* next, const int& d)
{
	setData(d);
	setNextNode(next);
	setPrevNode(prev);
}


void Node::setData(const int& d)
{
	data = d;
}
void Node::setNextNode(Node* n)
{
	nextNode = n;
}
void Node::setPrevNode(Node* p)
{
	prevNode = p;
}


int Node::getData()
{
	return data;
}
Node* Node::getNextNode()
{
	return nextNode;
}
Node* Node::getPrevNode()
{
	return prevNode;
}