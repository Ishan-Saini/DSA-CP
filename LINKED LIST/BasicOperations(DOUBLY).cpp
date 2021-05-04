#include <iostream>
using namespace std;

struct node {
	int data;
	node *prev;
	node *next;
	node(int x)
	{
		data = x;
		prev = NULL;
		next = NULL;
	}
};

node *insertAtBegin(node *head, int x)
{
	node *temp = new node(x);

	if (head == NULL)
		return temp;
	temp->next = head;
	head->prev = temp;
	return temp;
}

node *insertAtEnd(node *head, int x)
{
	node *temp = new node(x);

	if (head == NULL)
		return temp;
	node *t = head;

	while (t->next != NULL)
		t = t->next;
	t->next = temp;
	temp->prev = t;

	return head;
}

node *reverse(node *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	node *t = head;
	node *temp = NULL;
	while (t != NULL)
	{
		temp = t->prev;
		t->prev = t->next;
		t->next = temp;
		t = t->prev;
	}

	return temp->prev;
}

void printList(node *head)
{
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

node *deleteAtBegin(node *head)
{
	if (head == NULL)
		return head;
	if (head->next == NULL)
	{
		delete head;
		return NULL;
	}
	node *t = head;
	head = head->next;
	head->prev = NULL;

	delete t;

	return head;
}

node *deleteAtEnd(node *head)
{
	if (head == NULL)
		return head;
	if (head->next == NULL)
	{
		delete head;
		return NULL;
	}

	node *t = head;
	while (t->next != NULL)
	{
		t = t->next;
	}

	t->prev->next = NULL;
	delete t;

	return head;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	node *head = new node(30);
	head = insertAtBegin(head, 20);
	head = insertAtBegin(head, 10);
	head = insertAtEnd(head, 40);

	head = reverse(head);
	head = deleteAtBegin(head);
	head = deleteAtEnd(head);
	printList(head);

	return 0;
}

