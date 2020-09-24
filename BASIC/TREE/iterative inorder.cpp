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

// time:- O(n)
// space:- O(h)
void itrInorder(node* root) {
	stack<node*>st;
	node* curr = root;

	cout << "INORDER :-  ";

	while (curr != NULL or st.empty() == false) {
		while (curr != NULL) {
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top();
		st.pop();
		cout << curr->data << " ";
		curr = curr->right;
	}

	cout << endl;
}

// time and space:- O(n)
void itrPreorder(node* root) {
	if (root == NULL) return;

	stack<node*> st;
	st.push(root);

	cout << "PREORDER :-  ";

	while (st.empty() == false) {
		node *curr = st.top();
		cout << curr->data << " ";
		st.pop();

		if (curr->right != NULL)
			st.push(curr->right);

		if (curr->left != NULL)
			st.push(curr->left);
	}
	cout << endl;
}

// time:- O(n)
// space:- O(h)
//SPACE OPTIMISED METHOD
void itrPreorderOp(node* root) {
	if (root == NULL) return;

	stack<node*> st;
	node *curr = root;

	cout << "PREORDER (optimised) :-  ";

	while (curr != NULL or st.empty() == false) {
		while (curr != NULL) {
			cout << curr->data << " ";

			if (curr->right != NULL)
				st.push(curr->right);

			curr = curr->left;
		}

		if (st.empty() == false) {
			curr = st.top();
			st.pop();
		}
	}
	cout << endl;
}

int main() {

	node * root = new node(10);
	root->left = new node(20);
	root->left->left = new node(40);
	root->left->right = new node(50);
	root->right = new node(30);

	itrInorder(root);
	itrPreorder(root);
	itrPreorderOp(root);

	return 0;
}
