#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> k >> n;
	int arr[n];

	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cout << "largest: " << arr[n - k] << endl;
	cout << "smallest: " << arr[k - 1] << endl;

	return 0;
}
