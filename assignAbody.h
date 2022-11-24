
#pragma once
#include"CircularDoublyList.h"




CircularDoublyList* partAbody(void)
{

	CircularDoublyList* L = new CircularDoublyList;
	int input = 0;
	while (1)
	{
		cout << "------------------------------------------" << endl;
		cout << ">>> 1  : Insert At First Node" << endl;
		cout << ">>> 2  : Insert At End Node" << endl;
		cout << ">>> 3  : Insert At  Specific Node" << endl;
		cout << ">>> 4  : Delete First Node" << endl;
		cout << ">>> 5  : Delete End Node" << endl;
		cout << ">>> 6  : Print All Elements in Original Order" << endl;
		cout << ">>> 7  : Print All Elements in Reversed Order" << endl;
		cout << ">>> 8  : Remove Duplication" << endl;
		cout << ">>> 9  : Swap Head and Tail" << endl;
		cout << ">>> 10 : Search Element in List" << endl;
		cout << ">>> 11 : Sum All Elements in List and Get" << endl;
		cout << ">>> 12 : Sort The List in Ascending Order" << endl;
		cout << ">>> 13 : Delete Full List" << endl;
		cout << ">>> 14 : Delete Node Before Specific Element" << endl;
		
		cout << "Other Key To Exit" << endl;
		cout << "----------------------------------------------------------------" << endl;
		cout << "----------------------------------------------------------------" << endl;
		cin >> input;

		/////////////////////////////////////////////////////////////////////////////////////////

		if (input == 1)
		{
			int value = 0;
			cout << "Enter Element To Add : ";
			cin >> value;
			L->insertAtStart(value);
		}

		/////////////////////////////////////////////////////////////////////////////////////////



		else if (input == 2)
		{
			int value = 0;
			cout << "Enter Element To Add : ";
			cin >> value;
			L->insertAtEnd(value);

		}

		/////////////////////////////////////////////////////////////////////////////////////////



		else if (input == 3)
		{
			int value = 0;
			int ind = 0;
			cout << "Enter Element To Add : ";
			cin >> value;
			cout << "Enter Index No : ";
			cin >> ind;
			
			L->insertAtAnyNode(ind, value);

		}

		/////////////////////////////////////////////////////////////////////////////////////////


		else if (input == 4)
		{
			L->deleteAtStart();
		}

		/////////////////////////////////////////////////////////////////////////////////////////

		else if (input == 5)
		{
			L->deleteAtEnd();
		}

		
	

		//////////////////////////////////////////////////////////////////////////////////////////

		else if (input == 6)
		{
			cout << ".................................................................." << endl;
			cout << ">>> List : ";
			L->displayList();

			cout << "..................................................................." << endl;

		}

		//////////////////////////////////////////////////////////////////////////////////////////

		else if (input == 7)
		{

			cout << ".................................................................." << endl;
			cout << ">>> Revesed List : ";
			L->reverseList();

			cout << "..................................................................." << endl;
		}

		
		///////////////////////////////////////////////////////////////////////////////////////////////////

		else if (input == 8)
		{
			L->removeDuplicates();
		}


		///////////////////////////////////////////////////////////////////////////////////////////////////

		else if (input == 9)
		{
			L->swapHeadAndTail();
		}


		///////////////////////////////////////////////////////////////////////////////////////////////////

		else if (input == 10)
		{
			bool find = false;
			int val = 0;
			cout << ">>> Enter To Value to Find in List : ";
			cin >> val;

			find=L->SearchValue(val);
			cout << "-----------------------------------------------------------------" << endl;
			if (find == true)
				cout << ">>> The Element Found in List" << endl;
			else
				cout << ">>> The Element Not Found" << endl;

			cout << "-----------------------------------------------------------------" << endl;



		}


		///////////////////////////////////////////////////////////////////////////////////////////////////
		else if (input == 11)
		{
		
			int sum = L->totalSum();
		cout << "-----------------------------------------------------------------" << endl;
		
		cout << ">>> Total Sum Is : " << sum << endl;

		cout << "-----------------------------------------------------------------" << endl;



		}
		///////////////////////////////////////////////////////////////////////////////////////////////////
		else if (input == 12)
		{

		L->SortList();


		}
		//////////////////////////////////////////////////////////////////////////////////////////////////
		else if (input == 13)
		{
		L->deleteAll();
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////
		else if (input == 14)
		{
		int val = 0;
		cout << ">>> Enter Number To Delete Before Node :" << endl;
		cin >> val;
		L->deleteBefore(val);

		}

		///////////////////////////////////////////////////////////////////////////////////////////////////

		else
		{
			return L;
			break;
		}


	}

	return nullptr;
}