/*
	BREADTH FIRST SEARCH
	TIME : O(N)
	SPACE : O(N) or theta(W), W = width
*/

#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;

	node(int k) {
		data = k;
		left = NULL;
		right = NULL;
	}
};

// METHOD 1 (OUTPUTS IN THE SAME LINE)

void bfs(node *root)
{
	if (root == NULL)
		return;
	queue<node *> q;
	q.push(root);

	while (q.empty() == false)
	{
		node *temp = q.front();
		q.pop();
		cout << temp->data << " ";

		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
	}
}

// METHOD 2 (OUTPUTS LINE BY LINE)

void bfsSteps(node *root)
{
	if (root == NULL)
		return;
	queue <node *> q;
	q.push(root);
	q.push(NULL);

	while (q.size() > 1)
	{
		node *temp = q.front();
		q.pop();

		if (temp == NULL)
		{
			cout << '\n';
			q.push(NULL);
			continue;
		}

		cout << temp->data << " ";
		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
	}
}

// METHOD 1 (OUTPUTS LINE BY LINE USING TWO LOOPS)

void bfsStepsTwoLoops(node *root)
{
	if (root == NULL)
		return;
	queue <node *> q;
	q.push(root);

	while (q.empty() == false)
	{
		int count = q.size();
		for (int i = 0; i < count; ++i)
		{
			node *temp = q.front();
			q.pop();
			cout << temp->data << " ";

			if (temp->left != NULL)
				q.push(temp->left);
			if (temp->right != NULL)
				q.push(temp->right);
		}
		cout << '\n';
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	node *root = new node(10);
	root->left = new node(20);
	root->right = new node(30);
	root->left->left = new node(40);
	root->left->right = new node(50);
	root->right->left = new node(60);
	root->right->right = new node(70);
	cout << '\n';
	bfsStepsTwoLoops(root);

	return 0;
}

