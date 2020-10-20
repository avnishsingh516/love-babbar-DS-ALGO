// max value of arr[j]-arr[i] such that j>i
#include<bits/stdc++.h>
using namespace std;

// time :- O(n^2)
int maxDiff(int arr[], int n) {
	int res = arr[1] - arr[0];

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			res = max(res, arr[j] - arr[i]);

	}

	return res;
}

// OPTIMISED
// time:- O(n)
int maxDiffer(int arr[], int n) {
	int res = arr[1] - arr[0];
	int minVal = arr[0];

	for (int j = 1; j < n; j++) {
		res = max(res, arr[j] - minVal);
		minVal = min(arr[j], minVal);
	}

	return res;
}

int main()
{
	int arr[] = {2, 3, 10, 6, 4, 8, 1};

	cout << maxDiff(arr, 7) << " " << maxDiffer(arr, 7) << endl;

	return 0;
}