#pragma once
#include"CircularDoublyList.h"
#include"assignAbody.h"
int main()
{


	int input = 0;
	cout << ">>> 1  : Shuffle And Merge Two Lists :" << endl;
	cout << ">>> Else to Work With One List :" << endl;
	cin >> input;


	if (input != 1)
	{
		CircularDoublyList* L1 = partAbody();
		delete L1;
		L1 = nullptr;

	}
	else
	{
		CircularDoublyList* L1 = partAbody();
		CircularDoublyList* L2 = partAbody();

		CircularDoublyList* L3 = *L1 + *L2;
		CircularDoublyList* L4 = L1->shuffleMerger(L2);


		cout << "----------------------------------------------------------------" << endl;
		cout << ">>> List One : ";
		L1->displayList();
		cout << ">>> List Two : ";
		L2->displayList();
		cout << ">>> List One and List Two Merge : ";
		L4->displayList();
		cout << "----------------------------------------------------------------" << endl;


		cout << "----------------------------------------------------------------" << endl;
		cout << ">>> List One : ";
		L1->displayList();
		cout << ">>> List Two : ";
		L2->displayList();
		cout << ">>> List One and List Two Sum : ";
		L3->displayList();
		cout << "----------------------------------------------------------------" << endl;



		delete L1;
		delete L2;
		delete L3;
		delete L4;

		L1 = nullptr;
		L2 = nullptr;
		L3 = nullptr;
		L4 = nullptr;

	}

	
	
	
	system("pause");
	return 0;
}