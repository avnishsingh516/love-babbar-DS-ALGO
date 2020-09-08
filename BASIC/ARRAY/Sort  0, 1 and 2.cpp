// (IMP)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];

	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];

	}

	int low0 = 0, mid1 = 0, high2 = n - 1;

	while (mid1 <= high2) {

		//if element is arr[mid1]=0
		if (arr[mid1] == 0) {
			swap(arr[low0], arr[mid1]);
			low0++;
			mid1++;
		}
		//if element is arr[mid1]=2
		else if (arr[mid1] == 2) {
			swap(arr[high2], arr[mid1]);
			high2--;
			mid1++;
		}
		//if element is arr[mid1]=1
		else {
			mid1++;
		}
	}


	for (int i = 0 ; i < n ; i++) {
		cout << arr[i] << " ";

	}

	cout << endl;

	return 0;
}
