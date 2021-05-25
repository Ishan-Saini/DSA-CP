/*
	MERGE TWO SORTED LINKED LIST INTO A SINGLE SORTED LIST
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


node *mergeList(node *h1, node *h2)
{

	if (h1 == NULL)
		return h2;
	if (h2 == NULL)
		return h1;

	node *head = NULL, *tail = NULL, *a = h1, *b = h2;

	if (a->data < b->data)
	{
		head = tail = a;
		a = a->next;
	} else {
		head = tail = b;
		b = b->next;
	}

	while (a != NULL && b != NULL)
	{
		if (a->data <= b->data)
		{
			tail->next = a;
			tail = a;
			a = a->next;
		}
		else
		{
			tail->next = b;
			tail = b;
			b = b->next;
		}
	}

	if (a == NULL)
		tail->next = b;
	else
		tail->next = a;

	return head;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	node *head = NULL;
	head = insertAtBegin(head, 65);
	head = insertAtBegin(head, 50);
	head = insertAtBegin(head, 40);
	head = insertAtBegin(head, 25);
	head = insertAtBegin(head, 10);
	printList(head);
	cout << '\n';

	node *h1 = NULL;
	h1 = insertAtBegin(h1, 35);
	h1 = insertAtBegin(h1, 30);
	h1 = insertAtBegin(h1, 15);
	h1 = insertAtBegin(h1, 5);
	printList(h1);
	cout << '\n';

	h1 = mergeList(head, h1);
	printList(h1);

	return 0;
}
