//count the max no of consecutive ones
#include<bits/stdc++.h>
using namespace std;

// time:- O(n^2)
int maxCon(bool arr[], int n) {
	int res = 0;

	for (int i = 0; i < n; i++) {
		int count = 0;

		for (int j = i; j < n; j++) {

			if (arr[j] == 1)
				count++;
			else
				break;
		}

		res = max(res, count);
	}
	return res;
}


//OPTIMIZED
// time:- O(n)
int maxOne(bool arr[], int n) {
	int res = 0, curr = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)
			curr = 0;
		else {
			curr++;
			res = max(res, curr);
		}
	}
	return res;
}


int main() {

	bool arr[] = {1, 0, 1, 1, 0, 1, 1};
	cout << maxCon(arr, 7) << " " << maxOne(arr, 7) << endl;

	return 0;
}