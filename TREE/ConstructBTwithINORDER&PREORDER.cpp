/*
	CONSTRUCT A BINARY TREE USING INORDER AND PREORDER TRAVERSALS

	TIME COMPLEXITY : O(N^2)
	BUT WITH HASHING WE CAN ACHIEVE O(N)
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


int preIndex = 0;
node *construct(int in[], int pre[], int x, int y)
{
	if (x > y)
		return NULL;

	node *root = new node(pre[preIndex++]);
	int inIndex;
	for (int i = x; i <= y; ++i)
	{
		if (in[i] == root->data) {
			inIndex = i;
			break;
		}
	}

	root->left = construct(in, pre, x, inIndex - 1);
	root->right = construct(in, pre, inIndex + 1, y);

	return root;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	int in[] = { 40, 20, 50, 10, 30, 80, 70, 90 };
	int pre[] = { 10, 20, 40, 50, 30, 70, 80, 90 };
	int n = sizeof(in) / sizeof(int);
	node *root = construct(in, pre, 0, n - 1);
	cout << root->right->right->left->data;
	return 0;
}

