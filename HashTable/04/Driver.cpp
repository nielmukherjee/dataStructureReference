// Martin Cox
// CS 355: Fall 2012
// Assignment Number: 8
// Due Date: October 23, 2012
#include "HashTable.h"
#include <iostream>
#include <string>
using namespace std;

void PrintMenu();


int main(){
	
	HashTable<int> h_table(34);
	HashTable<int> h_assign;
	int data;

	PrintMenu();
	cout << "-->";
	char choice;
	cin >> choice;

	while(choice != 'q' && choice != 'Q'){
		
		if (choice == '!'){
			HashTable<int> h_copy(h_table);
			cout << "Result:" << "Print New Copy" << endl;
			h_copy.ShowContents(cout); cout << endl;
			h_copy.Insert(-10000);
			cout << "Result: " << "Print Modified Copy" << endl;
			h_copy.ShowContents(cout); cout << endl;
			cout << "Result: " << "Print Original Test List" << endl;
			h_table.ShowContents(cout); cout << endl;
		}
		else{
			switch (choice){
				case 'h':
				case 'H': PrintMenu(); break;
				case '+':
					cin >> data;/*
          h_table.Insert(10); // 3
    h_table.ShowContents(cout); cout << endl;
          h_table.Insert(11); // 4
    h_table.ShowContents(cout); cout << endl;
          h_table.Insert(12); // 5
    h_table.ShowContents(cout); cout << endl;
          h_table.Insert(13); // 6
    h_table.ShowContents(cout); cout << endl;
          h_table.Insert(14); // 0
    h_table.ShowContents(cout); cout << endl;
          h_table.Insert(15); // 1
    h_table.ShowContents(cout); cout << endl;
          h_table.Insert(16); // 2
    h_table.ShowContents(cout); cout << endl;
          h_table.Insert(17); // full
    h_table.ShowContents(cout); cout << endl;
          h_table.Insert(18);
          h_table.Insert(19);
          h_table.Insert(20);*/
					cout << "Number of Hits: " << h_table.Insert(data) << endl;
					break;		
				case '-':
					cin >> data;
					h_table.Remove(data);
					break;
				
				case 'i':
				case 'I':
          h_table.ShowFill(cout); break;
				
				case 'p':
				case 'P':
          h_table.ShowContents(cout); break;

				case '#':
					h_assign = h_table;
					h_assign.Insert(-100000);
					cout << "Modify New List" << endl;
					h_assign.ShowContents(cout); cout << endl;
					cout << "Old List should not be affected" << endl;
					h_table.ShowContents(cout); cout << endl;
					h_assign.~HashTable();
					cout << "Destroy New List" << endl;
					cout << "Old List should not be affected" << endl;
					h_table.ShowContents(cout); cout << endl;
					break;
				case '?':
					cin >> data;
					if (h_table.Search(data) != NULL)
						cout << "Result:" << data << "\tfound" << endl;
					else
						cout << "Result:" << data << "\tnot found" << endl;
					break;
				default:
					cout << "INVALID CHOICE, Choose Again" << endl;
			}

		}
    h_table.ShowContents(cout); cout << endl;
		cout << "-->";
		cin >> choice;
	}

	return 0;
}

void PrintMenu(){
	/*Commands borrowed from Lab*/
	cout << endl << endl;
	cout << "  Command Line Options" << endl;
	cout << "  H\tHelp: Show Comman Line Options" << endl;
	cout << "  +x\tInsert x in order" << endl;
	cout << "  -x\tRemove x" << endl;
  cout << "  !   : Test copy constructor" << endl;
  cout << "  #   : Test assignment operator, ClearList must work first before testing" << endl;
    
  cout << "  ?x  : Search rest of list for x " << endl;
  cout << "  I   : Show Fill" << endl;
  cout << "  P   : Show Contents" << endl;
  cout << "  Q   : Quit the test program" << endl;
  cout << endl << endl << endl;
}