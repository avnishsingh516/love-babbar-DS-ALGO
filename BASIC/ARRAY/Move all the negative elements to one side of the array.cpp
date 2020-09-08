#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];

	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	int j = 0;
	for (int i = 0 ; i < n ; i++) {
		//found a -ve number
		if (arr[i] < 0) {
			// to avoid unnecessary swapping
			if (i != j) {
				swap(arr[i], arr[j]);
			}
			j++;
		}
	}

	for (int i = 0 ; i < n ; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;



	return 0;
}
