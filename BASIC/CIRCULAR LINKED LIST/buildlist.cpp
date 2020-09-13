#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	int data;
	Node* next;

	Node(int d) {
		data = d;
		next = NULL;
	}
};

//O(n)
Node* insertBegin1(Node* head, int x) {
	Node* temp = new Node(x);

	if (head == NULL) {
		temp->next = temp;
	}
	else {
		Node* curr = head;

		while (curr->next != head) {
			curr = curr->next;
		}

		curr->next = temp;
		temp->next = head;
	}

	return temp;
}

//O(1) , efficient method
Node* insertBegin2(Node* head, int x) {
	Node* temp = new Node(x);

	if (head == NULL) {
		temp->next = temp;
		return temp;
	}
	else {
		//insertion after the head
		temp->next = head->next;
		head->next = temp;

		//swapping of data with new and head node
		int t = head->data;
		head->data = temp->data;
		temp->data = t;

		return head;

	}
}

//O(n)
// same as insertBegin1
Node* insertEnd1(Node* head, int x) {
	Node* temp = new Node(x);

	if (head == NULL) {
		temp->next = temp;
		return temp;
	}
	else {
		Node* curr = head;

		while (curr->next != head) {
			curr = curr->next;
		}

		curr->next = temp;
		temp->next = head;

		return head;
	}
}

//O(1) , efficient method
Node* insertEnd2(Node* head, int x) {
	Node* temp = new Node(x);

	if (head == NULL) {
		temp->next = temp;
		return temp;
	}
	else {
		//insertion after the head
		temp->next = head->next;
		head->next = temp;

		//swapping of data with new and head node
		int t = head->data;
		head->data = temp->data;
		temp->data = t;

		return temp;

	}
}

//using for loop
void printList1(Node* head) {

	if (head == NULL) {
		return ;
	}

	cout << head->data << " ";

	for (Node* curr = head->next; curr != head; curr = curr->next) {
		cout << curr->data << " ";
	}
}

//using do-while loop // more efficient method
void printList2(Node* head) {

	if (head == NULL) {
		return ;
	}

	Node* temp = head;

	do {
		cout << temp->data << " ";
		temp = temp->next;

	} while (temp != head);
}

//O(n)
Node* delHead1(Node* head) {
	if (head == NULL)
		return NULL;

	if (head->next == head) {
		delete head;
		return NULL;
	}

	Node* curr = head;

	while (curr->next != head) {
		curr = curr->next;
	}

	curr->next = head->next;
	delete head;
	return (curr->next);

}

// O(1)
Node* delHead2(Node* head) {
	if (head == NULL)
		return NULL;

	if (head->next == head) {
		delete head;
		return NULL;
	}

	// copy the head->next data in head data
	head->data = head->next->data;

	Node* temp = head->next;
	head->next = head->next->next;

	delete temp;
	return head;

}

Node* delKthNode(Node* head, int k) {
	if (head == NULL) return NULL;

	if (k == 1)
		return delHead1(head);

	Node* curr = head;
	for (int i = 0 ; i < k - 2 ; i++) {
		curr = curr->next;
	}

	Node* temp = curr->next;
	curr->next = curr->next->next;

	delete temp;
	return head;
}



int main() {

	Node* head = NULL;

	for (int i = 0 ; i < 6 ; i++) {
		head = insertBegin1(head, i);
	}


	head = insertBegin2(head, 10);

	head = insertEnd1(head, 100);

	head = insertEnd2(head, 15);

	head = delHead1(head);

	head = delHead2(head);

	head = delKthNode(head, 5);



	printList1(head);
	cout << endl;
	printList2(head);
	cout << endl;

	return 0;
}