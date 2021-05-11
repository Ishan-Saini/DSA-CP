/*
	FIND THE MIDDLE NODE IN A LINKED LIST.
	IN CASE OF EVEN NUMBER OF NODES, OUTPUT THT SECOND NODE OF THE MIDDLE PAIR
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


int middleNode(node *head)
{
	if (head == NULL)
		return 0;

	node *fast = head;
	node *slow = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow->data;

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

	cout << '\n' << middleNode(head);

	return 0;
}
