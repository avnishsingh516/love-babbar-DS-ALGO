//maximum length even odd subarray in alternative
#include<bits/stdc++.h>
using namespace std;

// time:- O(n^2)
int maxEvenOdd(int arr[], int n) {

	int res = 1;
	for (int i = 0; i < n; i++) {

		int curr = 1;
		for (int j = i + 1; j < n; j++) {

			if ((arr[j] % 2 == 0 && arr[j - 1] % 2 != 0) || (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0))
				curr++;
			else
				break;

		}
		res = max(res, curr);
	}
	return res;
}

// based on kadane's algo
// time:- O(n)
int maxEveOdd(int arr[], int n) {
	int res = 1, curr = 1;

	for (int i = 1; i < n; i++) {
		if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0)) {
			curr++;
			res = max(res, curr);
		}
		else {
			curr = 1;
		}

	}

	return res;
}


int main() {

	int arr[] = {5, 10, 20, 6, 3, 8};
	int n = 6;

	cout << maxEvenOdd(arr, n) << " " << maxEveOdd(arr, n) << endl;

	return 0;
}