/*
	CALCULATE DIAMETER OF A BINARY TREE

	Diameter of a binary tree is the number of nodes on the longest path between
	two leaf nodes.

	TWO SOLUTIONS :

	1. USING HEIGHT FUNCTION : RETURN DIAMETER | TIME COMPLEXITY : O(N^2)
	2. MODIFYING HEIGHT FUNCTION : GLOBAL VARIABLE IS USED TO DETERMINE DIAMETER | TIME COMPLEXITY : O(N)
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

/*

METHOD 1 -

int calcHeight(node *root)
{
	if (root == NULL)
		return 0;

	return max(calcHeight(root->left), calcHeight(root->right)) + 1;
}


int calcDiameter(node *root)
{
	if (root == NULL)
		return 0;
	int d1 = calcHeight(root->left) + calcHeight(root->right) + 1;
	int d2 = calcDiameter(root->left);
	int d3 = calcDiameter(root->right);

	return max(d1, max(d2, d3));
}

*/

// METHOD 2 -

int maxDia = 0;
int height(node *root)
{
	if (root == NULL)
		return 0;

	int hl = height(root->left);
	int hr = height(root->right);

	maxDia = max( hl + hr + 1, maxDia );
	return max(hl, hr) + 1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	node *root = new node(20);
	root->left = new node(15);
	root->right = new node(5);
	root->left->left = new node(7);
	root->left->right = new node(8);
	root->right->left = new node(2);
	root->right->right = new node(3);
	root->left->left->left = new node(18);
	root->left->right->right = new node(28);
	root->right->left->right = new node(13);
	root->right->right->left = new node(34);
	root->left->left->left->left = new node(38);
	cout << '\n';
	int h = height(root);
	cout << maxDia;
	return 0;
}

