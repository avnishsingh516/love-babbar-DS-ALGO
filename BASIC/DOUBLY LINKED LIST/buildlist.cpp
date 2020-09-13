#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node(int d) {
		data = d;
		next = prev = NULL;
	}
};

Node* insertBegin(Node*head , int data) {
	Node* temp = new Node(data);

	temp->next = head;

	if (head != NULL) {
		head->prev = temp;
	}

	return temp;
}

Node* insertEnd(Node* head, int data) {
	if (head == NULL) {
		head = insertBegin(head, data);
		return head;
	}
	Node* tail = head;
	Node* temp = new Node(data);

	while (tail->next != NULL) {
		tail = tail->next;
	}

	tail->next = temp;
	temp->prev = tail;

	return head;
}

Node* reverseList(Node* head) {
	if (head == NULL || head->next == NULL )
		return head;

	Node* temp = NULL;
	Node* curr = head;

	while (curr != NULL) {
		//swapping
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;

		curr = curr->prev;
	}

	//for last node
	temp = temp->prev;

	return temp;

}

Node* delHead(Node* head) {
	if (head == NULL) {
		return NULL;
	}

	if (head->next == NULL) {
		delete head;
		return NULL;
	}
	else {
		Node* temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
		return head;
	}
}

Node* delTail(Node* head) {
	if (head == NULL) {
		return NULL;
	}

	if (head->next == NULL) {
		delete head;
		return NULL;
	}
	else {
		Node* tail = head;
		while (tail->next != NULL) {
			tail = tail->next;
		}

		tail->prev->next = NULL;
		delete tail;
		return head;
	}
}

void printList(Node* head) {
	cout << "PRINT IN FORWARD DIR:-> ";
	while (head->next != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << head->data << endl;

	cout << "PRINT IN BACKWARD DIR:-> ";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->prev;
	}
	cout << endl;


}


int main() {

	Node* head = NULL;

	for (int i = 0 ; i < 6 ; i++) {
		head = insertBegin(head, i);
	}

	printList(head);

	head = insertEnd(head, 6);
	printList(head);

	head = reverseList(head);
	printList(head);

	head = delHead(head);
	printList(head);

	head = delTail(head);
	printList(head);

	return 0;
}