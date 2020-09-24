#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left, *right;

	node(int d) {
		data = d;
		left = right = NULL;
	}
};

//recursive
// time :- O(h)
// aux space:- O(h)
bool search(node* root, int x) {
	if (root == NULL)
		return false;

	else if (root->data == x)
		return true;

	else if (root->data > x)
		return search(root->left, x);

	else
		return search(root->right, x);

}

//iterative
// time :- O(h)
// aux space:- O(1)
bool searchitr(node*root , int x) {

	while (root != NULL) {

		if (root -> data == x)
			return true;

		else if (root->data < x)
			root = root->right;

		else
			root = root->left;
	}

	return false;
}

//recursive
// time :- O(h)
// aux space:- O(h)
node *insert (node*root, int x) {

	if (root == NULL)
		return (new node(x));

	else if (root->data < x)
		root->right = insert(root->right, x);

	else if (root->data > x)
		root->left = insert(root->left, x);

	return root;
}

//iterative
// time :- O(h)
// aux space:- O(1)
node *insertitr(node* root, int x) {

	node *temp = new node(x);
	node* parent = NULL, *curr = root;

	while (curr != NULL) {
		parent = curr;

		if (curr->data > x)
			curr = curr->left;

		else if (curr->data < x)
			curr = curr->right;

		else
			//if the data is already present,
			// return the root without insertion
			return root;

	}

	//for empty tree
	if (parent == NULL)
		return temp;

	if (parent->data > x)
		parent->left = temp;

	else
		parent->right = temp;

	return root;
}

//gives the nearest largest number to the root
//gives only when right child is not empty , it does not give general successor
node* getSuccessor(node* curr) {
	curr = curr->right;

	while (curr != NULL and curr->left != NULL)
		curr = curr->left;

	return curr;
}

//recursive
// time :- O(h)
// aux space:- O(h)
node *delnode(node*root , int x) {
	if (root == NULL)
		return root;

	if (root->data > x)
		root->left = delnode(root->left, x);

	else if (root->data < x)
		root->right = delnode(root->right, x);

	else {
		//only right child is present
		if (root->left == NULL) {
			node *temp = root->right;
			delete root;
			return temp;
		}

		//only left child is present
		else if (root->right == NULL) {
			node *temp = root->left;
			delete root;
			return temp;
		}
		//above both condition can also work fine if there is no child present

		//both child are present
		else {
			node* succ = getSuccessor(root);
			root->data = succ->data;
			root->right = delnode(root->right, succ->data);
		}

		return root;
	}
}

//print
void printPreorder( node* root)
{
	if (root == NULL)
		return;

	/* first print data of node */
	cout << root->data << " ";

	/* then recur on left sutree */
	printPreorder(root->left);

	/* now recur on right subtree */
	printPreorder(root->right);
}

int main() {

	node *root = NULL;
	root = insert(root, 50);
	insert(root, 50);
	insert(root, 30);
	insert(root, 10);
	insert(root, 40);
	insertitr(root, 70);
	insertitr(root, 60);
	insertitr(root, 80);
	insert(root, 55);

	cout << search(root, 10) << " " << searchitr(root, 11) << endl;
	printPreorder(root);
	cout << endl;

	delnode(root, 50);

	printPreorder(root);

	return 0;
}