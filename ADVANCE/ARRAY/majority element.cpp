#include<bits/stdc++.h>
using namespace std;

// time:- O(n)
int maj(int arr[], int n) {
	for (int i = 0; i < n ; i++) {

		int count = 1;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j])
				count++;
		}

		if (count > n / 2)
			return arr[i];
	}

	return -1;
}


// OPTIMIZED
// time:- O(n)
int majority(int arr[], int n) {
	int res = 0, count = 1;

	//find a acandidate
	for (int i = 1; i < n; i++) {
		if (arr[res] == arr[i])
			count++;
		else
			count--;

		if (count == 0) {
			res = i;
			count = 1;
		}
	}

	count = 0;

	//check if candidate is actually a majority
	for (int i = 0; i < n; i++) {
		if (arr[res] == arr[i])
			count++;
	}

	if (count <= n / 2)
		return -1;

	return arr[res];
}

int main() {

	int arr[] = {8, 7, 6, 8, 6, 6, 6, 6};

	cout << maj(arr, 8) << " " << majority(arr, 8) << endl;

	return 0;
}

/*
METHOD OPTIMIZED:-(Using Moore’s Voting Algorithm):

Approach: This is a two-step process.
The first step gives the element that maybe the majority element in the array. If there is a majority element in an array, then this step will definitely return majority element, otherwise, it will return candidate for majority element.
Check if the element obtained from the above step is majority element. This step is necessary as there might be no majority element.
Step 1: Finding a Candidate
The algorithm for the first phase that works in O(n) is known as Moore’s Voting Algorithm. Basic idea of the algorithm is that if each occurrence of an element e can be cancelled with all the other elements that are different from e then e will exist till end if it is a majority element.

Step 2: Check if the element obtained in step 1 is majority element or not.
Traverse through the array and check if the count of the element found is greater than half the size of the array, then print the answer else print “No majority element”.

Algorithm:
1. Loop through each element and maintains a count of majority element, and a majority index, maj_index
2. If the next element is same then increment the count if the next element is not same then decrement the count.
3. if the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
4. Now again traverse through the array and find the count of majority element found.
5. If the count is greater than half the size of the array, print the element.
6. Else print that there is no majority element
*/