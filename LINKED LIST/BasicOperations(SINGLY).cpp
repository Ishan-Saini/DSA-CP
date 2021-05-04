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

node *insertAtEnd(node *head, int x)
{
	node *temp = new node(x);
	if (head == NULL)
	{
		return temp;
	}
	node *t2 = head;
	while (t2->next != NULL)
	{
		t2 = t2->next;
	}

	t2->next = temp;
	return head;
}

node *insertAtPos(node *head, int pos, int x)
{
	node *temp = new node(x);

	if (pos == 1) {
		temp->next = head;
		return temp;
	}

	node *t = head;
	int i = 1;
	while (t != NULL && i < pos - 1)
	{
		t = t->next;
		i++;
	}

	if (t == NULL) {
		delete temp;
		return head;
	}

	node *t2 = t->next;
	t->next = temp;
	temp->next = t2;

	return head;
}


node *deleteFirst(node *head)
{
	if (head == NULL)
		return head;
	node *temp = head->next;
	delete head;

	return temp;
}

node *deleteLast(node *head)
{
	if (head == NULL)
		return NULL;
	if (head->next == NULL) {
		delete head;
		return NULL;
	}
	node *temp = head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}

	delete temp->next;
	temp->next = NULL;
	return head;
}

int searchList(node *head, int x)
{
	node *temp = head;
	int pos = 1;
	while (temp != NULL && temp->data != x)
	{
		temp = temp->next;
		pos++;
	}
	if (temp == NULL)
		return 0;
	else
		return pos;
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
	head = insertAtEnd(head, 30);
	head = deleteFirst(head);
	head = deleteLast(head);
	head = insertAtPos(head, 3, 17);

	printList(head);
	cout << endl;
	int isPresent = searchList(head, 10);
	cout << isPresent;


	return 0;
}
