/*
	FIND THE NODE WITH MAXIMUM VALUE IN A TREE
	TIME COMPLEXITY : O(N)
	SPACE :
			RECURSIVE : O(H) , USEFUL WHEN THERE ARE MANY NODES AT ONE LEVEL
			ITERATIVE : (W), USEFUL WHEN A TREE IS SKEWED
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


int getMaximum(node *root)
{

	if (root == NULL)
		return INT_MIN;

	return max(root->data, max(getMaximum(root->left), getMaximum(root->right)));

	/*
	ITERATIVE METHOD

	if (root == NULL)
			return -1;
		queue <node *> q;
		q.push(root);
		int maximum = root->data;
		while (q.empty() == false)
		{
			node *temp = q.front();
			q.pop();
			if (temp->data > maximum)
				maximum = temp->data;

			if (temp->left != NULL)
				q.push(temp->left);
			if (temp->right != NULL)
				q.push(temp->right);
		}
		return maximum;
		*/
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
#endif

	node *root = new node(10);
	root->left = new node(20);
	root->right = new node(30);
	root->left->left = new node(80);
	root->left->right = new node(90);
	root->right->left = new node(60);
	root->right->right = new node(70);
	cout << '\n';
	cout << getMaximum(root);

	return 0;
}

