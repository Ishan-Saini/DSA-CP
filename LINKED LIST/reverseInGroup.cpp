/*
	REVERSE A GIVEN LINKED LIST IN GROUPS OF K SIZE.
	E.G. 1 2 3 4 5 6 7 8

	K = 3

	3 2 1 6 5 4 8 7
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

node *reverseInGroup(node *head, int  k)
{
	/*
	RECURSIVE SOLUTION -> O(N) TIME
						  O(N/K) SPACE

	node *prev = NULL, *next = NULL;
	node *cur = head;
	int count = 0;
	while (cur != NULL && count < k)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		count++;
	}

	if (next != NULL)
	{
		node *rest_head = reverseInGroup(next, k);
		head->next = rest_head;
	}

	return prev;
	*/


	/*
	ITERATIVE SOLUTION -> O(N) TIME
						  O(1) SPACE
	*/

	node *cur = head, *prevFirst = NULL;
	bool isFirstPass = true;
	while (cur != NULL)
	{
		int count = 0;
		node * first = cur, *prev = NULL;

		while (cur != NULL && count < k)
		{
			node *next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
			count++;
		}
		if (isFirstPass) {
			head = prev;
			isFirstPass = false;
		}
		else {
			prevFirst->next = prev;
		}
		prevFirst = first;
	}
	return head;
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
	head = reverseInGroup(head, 3);
	printList(head);



	return 0;
}
