#pragma once
#include"CircularDoublyList.h"



CircularDoublyList::CircularDoublyList()
{
	head = nullptr;
	tail = nullptr;

}

CircularDoublyList::~CircularDoublyList()
{
		while (head != nullptr)
		{
			deleteAtStart();

		}


}


void CircularDoublyList::insertAtStart(const int& value)
{
	if (head == nullptr)
	{

		Node* newNode = new Node(nullptr, nullptr, value);
		head = tail = newNode;
		newNode->setNextNode(head);
		newNode->setPrevNode(tail);
		
		
	}
	else
	{
		Node* temp = head;
		Node* newNode = new Node(tail, temp, value);
		newNode->getNextNode()->setPrevNode(newNode);
		head = newNode;
		tail->setNextNode(head);
	}
}
void CircularDoublyList::insertAtEnd(const int& value)
{
	if (head == nullptr)
	{

		Node* newNode = new Node(nullptr, nullptr, value);
		head = tail = newNode;
		newNode->setNextNode(head);
		newNode->setPrevNode(tail);
	}
	else
	{
		Node* temp = tail;
		Node* newNode = new Node(temp, head, value);
		tail->setNextNode(newNode);
		tail = newNode;
		head->setPrevNode(tail);
	}

}
void CircularDoublyList::insertAtAnyNode(const int& index,const int& value)
{

	if (head != nullptr)
	{
		int totalNodes = noOfNodes();

		if (index > 0 && index <= totalNodes)
		{


			if (index == 1)
			{
				insertAtStart(value);
			}
			else if (index == totalNodes)
			{
				insertAtEnd(tail->getData());
				tail->getPrevNode()->setData(value);
			}
			else
			{

				Node* currentNode = head->getNextNode();
				for (int i = 1; i < index-1; i++)
				{
					currentNode = currentNode->getNextNode();
				}

				Node* newNode = new Node(currentNode->getPrevNode(), currentNode, value);
				newNode->getPrevNode()->setNextNode(newNode);
				currentNode->setPrevNode(newNode);
				


			}

		}
	}

}

bool CircularDoublyList::SearchValue(const int& value)
{
	if (head != nullptr)
	{

		Node* temp = head;

		while (1)
		{
			if (temp->getData() == value)
			{
				return true;
			}
			temp = temp->getNextNode();

			if (temp == head)
			{
				return false;
			}
		}
	}
	else
		cout << ">>> The List is Empty" << endl;


	return false;
}

void CircularDoublyList::deleteAtStart(void)
{
	if (head != nullptr)
	{
		
		if (head==tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			Node* temp = head->getNextNode();
			delete head;
			temp->setPrevNode(tail);
			head = temp;
			tail->setNextNode(head);

		}

		
	}
	else
		cout << ">>> The List is Empty" << endl;

}
void CircularDoublyList::deleteAtEnd(void)
{

	if (head != nullptr)
	{


		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			Node* temp = tail->getPrevNode();
			delete tail;
			temp->setNextNode(head);
			head->setPrevNode(temp);
			tail = temp;

		}



		cout << "-----------------------------------------------" << endl;
		cout << ">>> The End Node Is Removed" << endl;
		cout << "-----------------------------------------------" << endl;


	}
	else
		cout << ">>> The List is Empty" << endl;

}

void CircularDoublyList:: displayList(void) const
{
	if (head != nullptr)
	{
		Node* currentNode = head;

		while (1)
		{


			cout << currentNode->getData() << " ";
			currentNode = currentNode->getNextNode();
			if (currentNode == head)
			{
				break;
			}

			
		}
		cout << endl;
	}
	else
		cout << ">>> The List is Empty" << endl;

}

int CircularDoublyList::noOfNodes(void)
{
	int count = 0;

	if (head != nullptr)
	{

		Node* currentNode = head;

		while (1)
		{


			count++;
			currentNode = currentNode->getNextNode();
			if (currentNode == head)
			{
				break;
			}


		}
	}
	

	return count;
}


void CircularDoublyList::reverseList(void) const
{

	if (tail != nullptr)
	{

		Node* currentNode = tail;

		while (1)
		{


			cout << currentNode->getData() << " ";
			currentNode = currentNode->getPrevNode();
			if (currentNode == tail)
			{
				break;
			}


		}
		cout << endl;
	}
	else
		cout << ">>> The List is Empty" << endl;

}
int CircularDoublyList::totalSum(void)
{
	int total = 0;
	if (head != nullptr)
	{
	
		Node* curr = head;
		while (1)
		{
			total = total + curr->getData();
			curr = curr->getNextNode();

			if (curr == head)
			{
				break;
			}
		}
	}

	return total;
}
void CircularDoublyList::swapHeadAndTail(void)
{
	if (head != nullptr && tail != nullptr)
	{
		int temp = head->getData();
		head->setData(tail->getData());
		tail->setData(temp);
	}
	else
		cout << ">>> The List is Empty " << endl;
	

}

void CircularDoublyList::removeDuplicates(void)
{

	if (head != nullptr && head!=tail)
	{
		SortList();

		Node* current = head;
		Node* tempStore = nullptr;
		bool find = false;

		while (1)
		{
			find = false;

			if (current->getData() == current->getNextNode()->getData())
			{
				if (current->getNextNode()==tail)
				{
					deleteAtEnd();
				}
				else
				{
					tempStore = current->getNextNode()->getNextNode();
					delete current->getNextNode();
					current->setNextNode(tempStore);
					tempStore->setPrevNode(current);
					find = true;
					

				}
			}

			if (find == false)
			{
				current = current->getNextNode();

				if (current == head)
				{
					break;
				}

			}
		}

	}


}

void CircularDoublyList::SortList(void)
{

	if (head != nullptr)
	{

		Node* maxValue =head;
		Node* minValue = nullptr;
		int temp = 0;
		while (1)
		{




			minValue = maxValue->getNextNode();
			while (minValue!=head)
			{


				if (maxValue->getData() > minValue->getData())
				{

					temp = maxValue->getData();
					maxValue->setData(minValue->getData());
					minValue->setData(temp);



				}


				if (minValue == head)
				{
					break;
				}

				minValue = minValue->getNextNode();
			}











			maxValue = maxValue->getNextNode();
			if (maxValue == head)
			{
				break;
			}


		}
		cout << endl;


	}
	else
	{
		cout << ">>> The List is Empty" << endl;
	}


}


Node* CircularDoublyList::getHead(void)
{
	return head;
}
Node* CircularDoublyList::getTail(void)
{
	return tail;
}


 CircularDoublyList* CircularDoublyList::shuffleMerger(CircularDoublyList* L2)
{
	 if (head != nullptr || L2->getHead() != nullptr)
	 {
		
		 CircularDoublyList* L3 = new CircularDoublyList();
		 Node* list1 = head;
		 Node* list2 = L2->getHead();

		 int count = 0;

		 while (1)
		 {


			 if (list1 != head)
			 {
				 L3->insertAtEnd(list1->getData());
				 list1 = list1->getNextNode();
			 }

			 if (list2 != L2->getHead())
			 {
				 L3->insertAtEnd(list2->getData());
				 list2 = list2->getNextNode();
			 }

			 if (count == 0)
			 {
				 L3->insertAtEnd(list1->getData());
				 list1 = list1->getNextNode();
				 L3->insertAtEnd(list2->getData());
				 list2 = list2->getNextNode();
				 count++;
			 }


			 if (list1 == head && list2 == L2->getHead())
			 {
				 break;
			 }

		 }

		 return L3;
	 }
	 else
	 {
		 cerr << ">>> Both List Are Empty" << endl;
	 }

	 return nullptr;
}


 void CircularDoublyList::deleteAll(void)
 {
	 if (head != nullptr)
	 {
		 while (head != nullptr)
		 {
			 deleteAtStart();
		 }


		 cout << "-----------------------------------------------" << endl;
		 cout << ">>> All Nodes Are Removed" << endl;
		 cout << "-----------------------------------------------" << endl;

	 }
	 else
		 cout << ">>> The List is Empty" << endl;
	 
 }


 void CircularDoublyList::deleteBefore(const int& valueFind)
 {

	 if (head != nullptr)
	 {
		 if (head->getData() == valueFind)
		 {
			 cout << ">>> There Is No Node Before The Targeted Node" << endl;
		 }
		 else if (head->getNextNode()->getData() == valueFind)
		 {
			 deleteAtStart();
		 }
		 else
		 {
			 Node* currentNode = head;
			 bool find = false;

			 while (1)
			 {
				 if (currentNode->getData() == valueFind)
				 {
					 find = true;
					 break;
				 }

				 currentNode = currentNode->getNextNode();
				 if (currentNode == head)
				 {
					 break;
				 }
			 }

			 if (find == false)
				 cout << ">>> The Value is not Found in List" << endl;
			 else
			 {

				 Node* prevPrevNode = currentNode->getPrevNode()->getPrevNode();
				 delete currentNode->getPrevNode();
				 currentNode->setPrevNode(prevPrevNode);
				 prevPrevNode->setNextNode(currentNode);

				 cout << "-----------------------------------------------" << endl;
				 cout << ">>> The Node Is Removed" << endl;
				 cout << "-----------------------------------------------" << endl;

			 }
		 }
	 }

 }



 CircularDoublyList* CircularDoublyList::operator+(const CircularDoublyList& L2)
 {

	 if (head != nullptr && L2.head != nullptr)
	 {
		 CircularDoublyList* L3 = new CircularDoublyList();

		 Node* listOneNode = tail;
		 Node* listTwoNode = L2.tail;

		 int tempOne = 0;
		 int tempTwo = 0;
		 int sum = 0;
		 int count = 0;
		 
		 while (1)
		 {

			 tempOne = 0;
			 tempTwo = 0;
			 
			 
			 if (listOneNode != tail )
			 {
				 tempOne = listOneNode->getData();
				 listOneNode = listOneNode->getPrevNode();
			 }
			 
			 if (listTwoNode != L2.tail )
			 {
				 tempTwo = listTwoNode->getData();
				 listTwoNode = listTwoNode->getPrevNode();

			 }
			 if (count == 0)
			 {

				 tempOne = listOneNode->getData();
				 listOneNode = listOneNode->getPrevNode();
				 tempTwo = listTwoNode->getData();
				 listTwoNode = listTwoNode->getPrevNode();

				 count++;
			 }
			 
			 sum = tempOne + tempTwo;

			 L3->insertAtStart(sum);


			 if (listOneNode == tail && listTwoNode == L2.tail)
			 {
				 break;
			 }

		 }



		 listOneNode = L3->tail;

		 while (1)
		 {
			 sum = 0;

			 if (listOneNode == L3->head)
			 {
				 if (listOneNode->getData() > 9)
				 {
					 listOneNode->setData(listOneNode->getData() % 10);
					 L3->insertAtStart(1);
				 }
			 }
			 else
			 {

				 if (listOneNode->getData() > 9)
				 {

					 listOneNode->setData(listOneNode->getData() % 10);

					 listOneNode->getPrevNode()->setData(listOneNode->getPrevNode()->getData()+1);
				 }

			 }


			 listOneNode = listOneNode->getPrevNode();
			 if (listOneNode == L3->tail)
			 {
				 break;
			 }
		 }

		 return L3;
	 }
	 else
		 cout << ">>> One Of The List Is Empty or Both" << endl;


	 return nullptr;
 }