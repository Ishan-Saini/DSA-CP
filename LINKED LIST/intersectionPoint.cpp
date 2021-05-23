/*
	FIND THE INTERSECTION POINT OF TWO LINKED LIST
*/


#include <iostream>
#include <cmath>
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


int intersection(node *h1, node *h2)
{
	node *t1 = h1, *t2 = h2;
	int c1 = 0, c2 = 0;
	while (t1 != NULL)
	{
		c1++;
		t1 = t1->next;
	}

	while (t2 != NULL)
	{
		c2++;
		t2 = t2->next;
	}

	int diff = abs(c1 - c2);
	node *first = NULL, *second = NULL;

	if (c1 > c2)
	{
		first = h1;
		second = h2;
	}
	else
	{
		first = h2;
		second = h1;
	}

	while (diff > 0)
	{
		first = first->next;
		diff--;
	}


	while (first != NULL && second != NULL)
	{
		if (first == second)
			return first->data;
		first = first->next;
		second = second->next;
	}

	return -1;
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

	return 0;
}
