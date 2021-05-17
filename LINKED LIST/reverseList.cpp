/*
	REVERSE A SINGLY LINKED LIST WITHOUT USING AUXILIARY SPACE
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


node *reverse(node *head)
{
	if (head == NULL)
		return NULL;

	node *cur = head;
	node *prev = NULL;
	node *nxt = NULL;
	while (cur != NULL)
	{
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}

	return prev;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	node *head = NULL;

	head = insertAtBegin(head, 20);
	head = insertAtBegin(head, 15);
	head = insertAtBegin(head, 10);
	head = insertAtBegin(head, 5);

	printList(head);
	head = reverse(head);
	cout << '\n';
	printList(head);

	return 0;
}
