/*
	CHECK IF THERE IS A LOOP IN  A LINKED LIST

	WE WILL USE FLOYD CYCLE DETECTION ALGORITHM
	1. Two pointers are used - Fast and slow (they move 2 and 1 node at a time
	respectively)
	2. If they meet at some point then that linked list contains a loop.
*/


#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;

	node(int x) {
		data = x;
		next = NULL;
	}
};

void printList(node *head)
{
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

node *insertAtBegin(node *head, int x)
{

	node *temp = new node(x);
	temp->next = head;

	return temp;
}


bool detectLoop(node *head)
{
	node *fast = head, *slow = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return true;
	}

	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	node *head = NULL;
	head = insertAtBegin(head, 35);
	head = insertAtBegin(head, 30);
	head = insertAtBegin(head, 25);
	head = insertAtBegin(head, 20);
	head = insertAtBegin(head, 15);
	head = insertAtBegin(head, 10);
	head = insertAtBegin(head, 5);
	printList(head);
	cout << '\n';
	cout << detectLoop(head);

	return 0;
}
