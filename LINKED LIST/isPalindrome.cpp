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


bool isPalindrome(node *head)
{
	if (head == NULL)
		return true;

	node *slow = head, *fast = head;

	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	node *rev = reverse(slow->next);

	node *c1 = head;
	while (rev != NULL)
	{
		if (c1->data != rev->data)
			return false;
		c1 = c1->next;
		rev = rev->next;
	}

	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	node *head = NULL;
	head = insertAtBegin(head, 40);
	head = insertAtBegin(head, 35);
	head = insertAtBegin(head, 30);
	head = insertAtBegin(head, 30);
	head = insertAtBegin(head, 35);
	head = insertAtBegin(head, 40);
	printList(head);
	cout << '\n';
	cout << isPalindrome(head);

	return 0;
}
