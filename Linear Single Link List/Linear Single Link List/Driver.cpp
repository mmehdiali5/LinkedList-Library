#include<iostream>
using namespace std;
#include"LSLL.h"

int main()
{
	LSLL<int>a;
	a.insertAtHead(11);
	a.insertAtTail(15);
	a.insertAtTail(20);
	a.insertAtTail(5);
	a.insertAtTail(10);
	a.display();
	cout << "\n";
	a.lessThanGreaterThanArrange();
	a.display();
	cout << "\n\n\n\n\n\n\n";
	return 0;
}

/*a.insertAtHead(10);
	a.insertAfter(10, 20);
	a.insertBefore(10, 30);
	a.insertAtTail(40);
	a.display();
	cout << "\n";
	a.removeAtTail();
	a.display();
	cout << "\n";
	a.removeAtHead();
	a.display();*/
	/*a.removeAtHead();
	a.insertAtHead(10);
	a.insertAfter(10, 20);
	a.display();
	cout << "\n";*/
	/*a.removeAtHead();
	a.display();*/
	//cout << "\n";
	//a.removeAfter(10);
	//a.display();
	//cout << "\n";
	//a.insertBefore(10, 30);
	//a.insertAfter(30,40);
	//a.display();
	//cout << "\n";
	//a.removeAfter(30);
	//a.display();
	/*a.insertAtHead(10);
	a.insertAtHead(20);
	a.insertAtHead(30);
	a.insertAtHead(40);
	a.display();
	cout << "\n";
	a.removeBefore(40);
	a.removeBefore(30);
	a.display();
	cout << "\n";
	a.removeBefore(10);
	a.display();
	cout << "\n";
	a.removeBefore(10);
	a.display();
	cout << "\n";
	a.removeBefore(10);
	a.display();
	cout << "\n";
	a.remove(10);*/
	/*for (int i = 1; i <= 10; i++)
	{
		if (i <= 5)
			a.insertAtTail(i);
		else
			a.insertAtHead(i);
	}
	a.display();
	cout << "\n";
	for (int i = 0; i <= 10; i++)
	{
		a.remove(i);
		a.display();
		cout << "\n";
	}*/
	/*a.insertAtTail(30);
	a.display();
	cout << "\n";
	a.insertAtTail(20);
	a.display();
	cout << "\n";
	a.insertAtTail(10);
	a.display();
	cout << "\n";
	a.insertBefore(30, 40);
	a.display();
	cout << "\n";
	a.insertBefore(10, 110);
	a.display();*/