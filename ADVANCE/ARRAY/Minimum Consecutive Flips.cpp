// Given a binary array, we need to find the minimum of number of group flips to make all array elements same.  In a group flip, we can flip any set of consecutive 1s or 0s.

#include<bits/stdc++.h>
using namespace std;

//Efficient
// time:- O(n)
void printGraph(bool arr[], int n) {
	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1]) {

			if (arr[i] != arr[0])
				cout << "FROM " << i << " TO ";
			else
				cout << i - 1 << endl;
		}
	}

	if (arr[n - 1] != arr[0])
		cout << n - 1 << endl;
}

int main() {

	bool arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 0};

	printGraph(arr, 9);

	return 0;
}