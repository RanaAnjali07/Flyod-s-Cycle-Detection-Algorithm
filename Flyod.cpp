
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

Node* head = NULL;
class Linkedlist {
public:

	void insert(int value)
	{
		Node* newNode = new Node(value);
		if (head == NULL)
			head = newNode;
		else {
			newNode->next = head;
			head = newNode;
		}
	}


	bool detectLoop()
	{
		Node *slowPointer = head,
			*fastPointer = head;

		while (slowPointer != NULL
			&& fastPointer != NULL
			&& fastPointer->next != NULL) {
			slowPointer = slowPointer->next;
			fastPointer = fastPointer->next->next;
			if (slowPointer == fastPointer)
				return 1;
		}

		return 0;
	}
};

int main()
{
	Linkedlist l1;

	l1.insert(11);
	l1.insert(12);
	l1.insert(13);
	l1.insert(14);
	l1.insert(15);


	Node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = head;



	if (l1.detectLoop())
		cout << "Loop exist in the"
			<< " linked list" << endl;
	else
		cout << "Loop does not exist "
			<< "in the linked list" << endl;

	return 0;
}
