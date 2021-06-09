#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
	node *random;

	node(int x) {
		data = x;
		next = NULL;
		random = NULL;
	}
};

void print(node *start)
{
	node *ptr = start;
	while (ptr)
	{
		cout << "Data = " << ptr->data << ", Random  = "
		     << ptr->random->data << endl;
		ptr = ptr->next;
	}
}

node *cloneRandomPointerList(node *head)
{
	node *cur = head;

	while (cur != NULL)
	{
		node *next = cur->next;
		cur->next = new node(cur->data);
		cur->next->next = next;
		cur = next;
	}
	cur = head;

	while (cur != NULL)
	{
		if (cur->next != NULL)
			cur->next->random = cur->random ? cur->random->next : cur->random;

		cur = cur->next ? cur->next->next : cur->next;
	}

	node *new_head = head->next;

	node *c1 = head, *c2 = new_head;

	while (c1 != NULL && c2 != NULL)
	{
		c1->next = c1->next ? c1->next->next : c1->next;

		c2->next = c2->next ? c2->next->next : c2->next;
		c1 = c1->next;
		c2 = c2->next;
	}

	return new_head;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	node* start = new node(1);
	start->next = new node(2);
	start->next->next = new node(3);
	start->next->next->next = new node(4);
	start->next->next->next->next = new node(5);

	// 1's random points to 3
	start->random = start->next->next;

	// 2's random points to 1
	start->next->random = start;

	// 3's and 4's random points to 5
	start->next->next->random =
	    start->next->next->next->next;
	start->next->next->next->random =
	    start->next->next->next->next;

	// 5's random points to 2
	start->next->next->next->next->random =
	    start->next;

	cout << "Original list : \n";
	print(start);

	cout << "\nCloned list : \n";
	node *cloned_list = cloneRandomPointerList(start);
	print(cloned_list);

	return 0;

}
