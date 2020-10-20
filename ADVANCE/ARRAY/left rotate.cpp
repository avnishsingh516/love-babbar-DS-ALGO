//left rotate an array by d
#include<bits/stdc++.h>
using namespace std;

//method 1:- naive
// time:- O(nd)
//space:- O(1)

//helper func
void leftRotateOne(int arr[], int n) {
	int temp = arr[0];
	for (int i = 1; i < n; i++) {
		arr[i - 1] = arr[i];
	}
	arr[n - 1] = temp;
}

void leftRotate1(int arr[], int n, int d) {
	for (int i = 0 ; i < d; i++) {
		leftRotateOne(arr, n);
	}
}

//method 2:- better
//time:- O(n)
// space:- O(d)
void leftRotate2(int arr[], int n, int d) {
	int temp[d];

	for (int i = 0; i < d; i++)
		temp[i] = arr[i];

	for (int i = d; i < n; i++)
		arr[i - d] = arr[i];

	for (int i = 0; i < d; i++)
		arr[n - d + i] = temp[i];
}

// method 3:- optimized
//time:- O(n)
// space:- O(1)

//helper func
void reverse(int arr[], int low, int high) {
	while (low < high) {
		swap(arr[low], arr[high]);
		low++;
		high--;
	}
}

void leftRotate3(int arr[], int n, int d) {
	reverse(arr, 0, d - 1);
	reverse(arr, d, n - 1);
	reverse(arr, 0, n - 1);
}

int main() {

	int n = 5;
	int arr[] = {1, 2, 3, 4, 5};

	for (int i = 0 ; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// leftRotate1(arr, n, 2);
	// leftRotate2(arr, n, 2);
	leftRotate3(arr, n, 3);

	for (int i = 0 ; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}