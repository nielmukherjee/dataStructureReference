/* Program to insert elements in a queue*/
#include<iostream>
#include<queue>            //Header-file for queue
using namespace std;

int main()
{
	priority_queue<int> p1;
	p1.push(35);              // inserting element in a queue
	p1.push(40);
	p1.push(95);
	while (!p1.empty())
	{
		cout << ' ' << p1.top();  //printing elements of queue
		p1.pop();
	}
}

/* Program to access an element of highest priority */
#include<iostream>
#include<queue>     //Header-file for queue
using namespace std;


int main()
{
	priority_queue<int> p1;
	p1.push(35);
	p1.push(40);
	p1.push(95);
	p1.push(25);

	cout << p1.top();      //fetch element of highest priority(maximum element) i.e 95
}

/* Program to delete elements in a queue*/

#include<iostream>
#include<queue>     //Header-file for queue
using namespace std;

int main()
{
	priority_queue<int> p1;
	p1.push(35);
	p1.push(40);
	p1.push(95);
	p1.push(20);
	// queue : 95 40 35 20

	p1.pop();            // queue :  40 35 20
	p1.pop();           // queue :  35  20

	while (!p1.empty())
	{
		cout << ' ' << p1.top();
		p1.pop();
	}

}

//Program of swap method
#include <iostream>  
#include <queue>  
using namespace std;
int main()
{
	priority_queue<int> p1, q1;

	//pushing value in p1.  
	p1.push(28);
	p1.push(69);
	p1.push(36);
	p1.push(23);
	p1.push(14);

	//pushing value in q1.  
	q1.push(10);
	q1.push(80);
	q1.push(32);
	q1.push(20);
	q1.push(15);

	p1.swap(q1);
	cout << "elements in p1 : ";

	while (!p1.empty())
	{

		cout << " " << p1.top() << ' ';
		p1.pop();

	}

	cout << '\n';
	cout << "elements in m1 : ";
	while (!q1.empty())
	{

		cout << " " << q1.top() << ' ';
		q1.pop();

	}
	return 0;

}

//c++ program to implement min-heap
#include<iostream>
#include<queue>     //Header-file for queue

using namespace std;
int main()
{
	// creates a min heap
	priority_queue <int, vector<int>, greater<int> > p1;

	p1.push(55);
	p1.push(1);
	p1.push(76);
	p1.push(39);
	p1.push(23);
	p1.push(49);
	p1.push(32);

	while (!p1.empty())
	{
		cout << "  " << p1.top() << " ";
		p1.pop();
	}

	return 0;
}