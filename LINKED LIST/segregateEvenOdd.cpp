/*
	SEGREGATE EVEN AND ODD NODES IN A LINKED LIST SUCH THAT ALL EVEN NODES COME
	FIRST FOLLOWED BY ODD NODES

	APPROACH : TAKE FOUR POINTERS eS, eE, oS, oE (read S as Start and E as End)
			   NOW BRING ODD AND EVEN NODES TOGETHER AD FORM A SEPERATE LIST
			   FOR BOTH OF THEM. THEN, JOIN THEM.
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


node *segregate(node *head)
{
	node *eS = NULL, *eE = NULL, *oS = NULL, *oE = NULL;
	node *cur = head;

	while (cur != NULL)
	{
		if (cur->data % 2 == 0)
		{
			if (eS == NULL)
			{
				eS = cur;
				eE = cur;
			}
			else {
				eE->next = cur;
				eE = eE->next;
			}
		}
		else {
			if (oS == NULL)
			{
				oS = cur;
				oE = cur;
			}
			else {
				oE->next = cur;
				oE = oE->next;
			}
		}

		cur = cur->next;
	}
	if (oS == NULL || oE == NULL)
		return head;

	eE->next = oS;
	oE->next = NULL;

	return eS;
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
	head = segregate(head);
	printList(head);

	return 0;
}
