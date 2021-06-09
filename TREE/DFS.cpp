/*
	Depth First Search
	TIME COMPLEXITY : O(N)
	SPACE COMPLEXITY : O(H) , H = HEIGHT
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

void inorder(node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void preorder(node *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
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
	return 0;
}

