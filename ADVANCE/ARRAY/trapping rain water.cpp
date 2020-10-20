//max water trap during the rain
#include<bits/stdc++.h>
using namespace std;

//time:- O(n^2)
int getWater(int arr[], int n) {
	int res = 0;

	for (int i = 1; i < n - 1; i++) {

		//left side
		int lmax = arr[i];
		for (int j = 0; j < i; j++) {
			lmax = max(lmax, arr[j]);
		}

		//right side
		int rmax = arr[i];
		for (int j = i + 1; j < n; j++) {
			rmax = max(rmax, arr[j]);
		}

		res = res + (min(lmax, rmax) - arr[i]);
	}

	return res;
}

//OPTIMIZED
//time and space:- O(n)
int stored(int arr[], int n) {
	int res = 0;
	int rmax[n], lmax[n];

	//left side
	lmax[0] = arr[0];
	for (int i = 1; i < n; i++)
		lmax[i] = max(lmax[i - 1], arr[i]);

	//right side
	rmax[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		rmax[i] = max(rmax[i + 1], arr[i]);

	for (int i = 1; i < n - 1; i++)
		res = res + (min(lmax[i], rmax[i]) - arr[i]);

	return res;
}



int main() {

	int arr[] = {5, 0, 6, 2, 3};
	cout << getWater(arr, 5) << " " << stored(arr, 5) << endl;

	return 0;
}