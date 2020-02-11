//	Template

//Data:  21 10 56 43 78 11 20 18

#include <iostream>
#include "orderedArrayListType.h"
#include "unorderedArrayListType.h"

using namespace std; 

void	print_console(void);
void	console_insert(orderedArrayListType &);
void	console_insert(unorderedArrayListType<double> &);

int main()
{
//	{
//		orderedArrayListType intList(25);               //Line 1
//
//		int number;                                     //Line 2
//
//		cout << "List 3: Enter 8 integers: ";           //Line 3
//
//		for (int count = 0; count < 8; count++)         //Line 4
//		{
//			cin >> number;                              //Line 5
//			intList.insert(number);                     //Line 6
//		}
//
//		cout << endl;                                   //Line 7
//		cout << "Line 8: intList: ";                    //Line 8
//		intList.print();                                //Line 9
//		cout << endl;       	                        //Line 10
//
//		cout << "Line 11: Enter the number to be " 
//			<< "deleted: ";                            //Line 11
//		cin >> number;                                  //Line 12
//		cout << endl;                                   //Line 13
//
//		intList.remove(number);                         //Line 14
//
//		cout << "Line 15: After removing " << number
//			<< " intList: ";                           //Line 15
//		intList.print();                                //Line 16
//		cout << endl;                                   //Line 17
//
//		cout << "Line 18: Enter the search item: ";     //Line 18
//
//		cin >> number;                                  //Line 19
//		cout << endl;                                   //Line 20
//
//		if (intList.seqSearch(number) != -1)            //Line 21
//			cout << "Line 22: " << number 
//				<< " found in intList." << endl;       //Line 22
//		else                                            //Line 23
//			cout << "Line 24: " << number 
//				<< " is not in intList." << endl;      //Line 24
//	}
//	cout << "\n\n=======TEST=======" << endl;
//	{
//		int size;
//
//		cout << "Enter the size of the list: ";
//		cin >> size;
//		orderedArrayListType	List(size);
//
//		int input = 0;
//		while (1)
//		{
//			print_console();
//			cin >> input;
//			if (input == 6)
//				break ;
//			switch (input)
//			{
//				int loc;
//				case 1:
//					console_insert(List);
//					break ;
//				case 2:
//					cout << "Enter a new number: ";
//					cin >> input;
//					cout << "Enter a location: ";
//					cin >> loc;
//					List.replaceAt(loc, input);
//					break ;
//				case 3:
//					cout << "Enter a number: ";
//					cin >> input;
//					loc = List.seqSearch(input);
//					if (loc < 0)
//						cout << "Not found." << endl;
//					else
//						cout << input << " is at index of " << loc << endl;
//					break ;
//				case 4:
//					cout << "Enter a number: ";
//					cin >> input;
//					List.remove(input);
//					break ;
//				case 5:
//					cout << "List: ";
//					List.print();
//					cout << endl;
//					break ;
//				default:
//					cout << "[!] Wrong input." << endl;
//			}
//			cin.ignore(256, '\n');
//			cin.clear();
//		}
//	}
	{
		unorderedArrayListType<double> doubleList(25);  //Line 1

		double number;                                  //Line 2

		cout << "List 3: Enter 8 doubles: ";            //Line 3

		for (int count = 0; count < 8; count++)         //Line 4
		{
			cin >> number;                              //Line 5
			doubleList.insert(number);                  //Line 6
		}

		cout << endl;                                   //Line 7
		cout << "Line 8: doubleList: ";                 //Line 8
		doubleList.print();                             //Line 9
		cout << endl;       	                        //Line 10

		cout << "Line 11: Enter the number to be " 
			<< "deleted: ";                             //Line 11
		cin >> number;                                  //Line 12
		cout << endl;                                   //Line 13

		doubleList.remove(number);                    //Line 14

		cout << "Line 15: After removing " << number
			<< " doubleList: ";                         //Line 15
		doubleList.print();                             //Line 16
		cout << endl;                                   //Line 17

		cout << "Line 18: Enter the search item: ";     //Line 18

		cin >> number;                                  //Line 19
		cout << endl;                                   //Line 20

		if (doubleList.seqSearch(number) != -1)         //Line 21
			cout << "Line 22: " << number 
				<< " found in doubleList." << endl;     //Line 22
		else                                            //Line 23
			cout << "Line 24: " << number 
				<< " is not in doubleList." << endl;    //Line 24
	}
	cout << "\n\n=======TEST=======" << endl;
	{
		int size;

		cout << "Enter the size of the list: ";
		cin >> size;
		unorderedArrayListType<double>	List(size);

		int	input = 0;
		double var = 0;

		while (1)
		{
			print_console();
			cin >> input;
			if (input == 6)
				break ;
			switch (input)
			{
				int loc;
				case 1:
					console_insert(List);
					break ;
				case 2:
					cout << "Enter a new number: ";
					cin >> var;
					cout << "Enter a location: ";
					cin >> loc;
					List.replaceAt(loc, var);
					break ;
				case 3:
					cout << "Enter a number: ";
					cin >> var;
					loc = List.seqSearch(var);
					if (loc < 0)
						cout << "Not found." << endl;
					else
						cout << var << " is at index of " << loc << endl;
					break ;
				case 4:
					cout << "Enter a number: ";
					cin >> var;
					List.remove(var);
					break ;
				case 5:
					cout << "List: ";
					List.print();
					cout << endl;
					break ;
				default:
					cout << "[!] Wrong input." << endl;
			}
			cin.ignore(256, '\n');
			cin.clear();
		}
	}

	return 0; 
}

void	print_console(void)
{
	cout << endl <<
		"[1] insert" << endl <<
		"[2] replace" << endl <<
		"[3] search" << endl <<
		"[4] remove" << endl <<
		"[5] print" << endl <<
		"[6] exit" << endl << "$>";
}

void	console_insert(orderedArrayListType &List)
{
	int input;

	while (1)
	{
		cout << endl <<
			"[1] insert at the front" << endl <<
			"[2] insert at the end" << endl <<
			"[3] insert at ..." << endl <<
			"[4] back to main console" << endl;
		cin >> input;
		if (input == 4)
			break ;
		switch (input)
		{
			int loc;
			case 1:
				cout << "Enter a new number: ";
				cin >> input;
				List.insert(input);
				break ;
			case 2:
				cout << "Enter a new number: ";
				cin >> input;
				List.insertEnd(input);
				break ;
			case 3:
				cout << "Enter a new number: ";
				cin >> input;
				cout << "Enter a location: ";
				cin >> loc;
				List.insertAt(loc, input);
				break ;
			default:
				cout << "[!] Wrong input." << endl;
				cin.ignore(256, '\n');
				cin.clear();
		}
	}
}

void	console_insert(unorderedArrayListType<double> &List)
{
	int input;
	double var;

	while (1)
	{
		cout << endl <<
			"[1] insert at the front" << endl <<
			"[2] insert at the end" << endl <<
			"[3] insert at ..." << endl <<
			"[4] back to main console" << endl;
		cin >> input;
		if (input == 4)
			break ;
		switch (input)
		{
			int loc;
			case 1:
				cout << "Enter a new number: ";
				cin >> var;
				List.insert(var);
				break ;
			case 2:
				cout << "Enter a new number: ";
				cin >> var;
				List.insertEnd(var);
				break ;
			case 3:
				cout << "Enter a new number: ";
				cin >> var;
				cout << "Enter a location: ";
				cin >> loc;
				List.insertAt(loc, var);
				break ;
			default:
				cout << "[!] Wrong input." << endl;
				cin.ignore(256, '\n');
				cin.clear();
		}
	}
}

