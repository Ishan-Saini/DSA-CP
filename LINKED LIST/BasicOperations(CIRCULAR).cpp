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
	if (head == NULL)
		return;

	node *t = head;

	do {
		cout << t->data << " ";
		t = t->next;
	} while (t != head);
}

node *insertAtBegin(node *head, int x)
{
	node *temp = new node(x);
	if (head == NULL) {
		temp->next = temp;
		return temp;
	}

	temp->next = head->next;
	head->next = temp;
	int t = head->data;
	head->data = temp->data;
	temp->data = t;

	return head;
}

node *insertAtEnd(node *head, int x)
{
	node *temp = new node(x);
	if (head == NULL)
	{
		temp->next = temp;
		return temp;
	}
	else {
		temp->next = head->next;
		head->next = temp;
		int t = temp->data;
		temp->data = head->data;
		head->data = t;
		return temp;
	}
}

node *deleteHead(node *head)
{

	if (head == NULL)
		return NULL;
	if (head->next == head)
	{
		delete head;
		return NULL;
	}

	/*
	O(N) SOLUTION

	node *t = head;
	while (t->next != head)
		t = t->next;
	t->next = t->next->next;
	delete head;
	return t->next;
	*/

	// O(1)
	int t = head->data;
	head->data = head->next->data;
	head->next->data = t;

	node *temp = head->next;
	head->next = head->next->next;
	delete temp;
	return head;

}

node *deleteAtKth(node *head, int k)
{
	if (head == NULL)
		return NULL;
	if (k == 1) {
		return deleteHead(head);
	}
	int i = 1;
	node *t = head;
	while (i < k - 1)
	{
		t = t->next;
		i++;
	}
	node *temp = t->next;
	t->next = t->next->next;
	delete temp;

	return head;
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
	head = insertAtEnd(head, 25);
	head = deleteHead(head);
	head = deleteAtKth(head, 1);
	printList(head);

	return 0;
}
