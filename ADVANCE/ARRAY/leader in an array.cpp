// leaders in an array
#include<bits/stdc++.h>
using namespace std;

// time:- O(n^2)
void leaders(int arr[], int n) {
	for (int i = 0 ; i < n ; i++) {
		bool flag = false;
		for (int j = i + 1; j < n ; j++) {
			if (arr[i] <= arr[j]) {
				flag = true;
				break;
			}
		}

		if (flag == false)
			cout << arr[i] << " ";
	}
	cout << endl;
}

// OPTIMISED
// time:- O(n)
// note:- the leaders are printed from right to left, i.e its o/p seems to be opposite of above one
void leader(int arr[], int n) {
	int curr_itr = arr[n - 1];
	cout << curr_itr << " ";

	for (int i = n - 2; i >= 0; i--) {
		if (curr_itr < arr[i]) {
			curr_itr = arr[i];
			cout << curr_itr << " ";
		}
	}
	cout << endl;
}


int main() {
	int arr[] = {7, 10, 4, 10, 6, 5, 2};

	leader(arr, 7);
	leaders(arr, 7);

	return 0;
}
