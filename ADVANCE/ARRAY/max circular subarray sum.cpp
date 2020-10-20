//maximum circular subarray sum
#include<bits/stdc++.h>
using namespace std;

// time:- O(n^2)
int maxCir(int arr[], int n) {
	int res = arr[0];

	for (int i = 0; i < n; i++) {
		int curr_max = arr[i];
		int curr_sum = arr[i];

		for (int j = 1; j < n; j++) {
			int index = (i + j) % n;
			curr_sum += arr[index];
			curr_max = max(curr_max, curr_sum);
		}

		res = max(res, curr_max);
	}
	return res;
}

//OPTIMIZED SOLn
//time:- O(n)

//find max subarray sum (kadanes algo)
int maxSubNormal(int arr[], int n) {
	int res = arr[0];
	int maxEnding = arr[0];

	for (int i = 1; i < n; i++) {
		maxEnding = max(maxEnding + arr[i], arr[i]);
		res = max(res, maxEnding);
	}

	return res;
}

int overallMax(int arr[], int n) {

	int max_normal = maxSubNormal(arr, n); //normal sum

	if (max_normal < 0)
		return max_normal;

	//calculate max circular subarray sum
	int arr_sum = 0;
	for (int i = 0; i < n; i++) {
		arr_sum += arr[i];
		arr[i] = -arr[i]; //invert the element +ve to -ve and vice-versa
	}

	int max_cir = arr_sum + maxSubNormal(arr, n);

	return max(max_normal, max_cir);
}



int main() {

	int arr[] = { 5, -2, 3, 4};

	cout << maxCir(arr, 4) << " " << overallMax(arr, 4) << endl;

	return 0;
}