// move all the zeroes to the end
#include<bits/stdc++.h>
using namespace std;

// time :- O(n^2)
void move(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		//find zero
		if (arr[i] == 0) {
			//find non-zero
			for (int j = i + 1; j < n; j++) {
				if (arr[j] != 0) {
					// swap aero to non-zero
					swap(arr[i], arr[j]);
				}
			}
		}
	}
}

// time:- O(n)
void moveZero(int arr[], int n) {
	int count = 0; //to count the non-zero
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			swap(arr[i], arr[count]);
			count++;
		}
	}
}


int main(int argc, char const *argv[])
{
	int arr[] = {10, 5, 0, 12, 8, 0, 9, 0};

	move(arr, 8);
	// moveZero(arr, 8);

	for (int i = 0 ; i < 8 ; i++)
		cout << arr[i] << " ";

	cout << endl;
	return 0;
}