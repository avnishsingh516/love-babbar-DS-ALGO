#include<bits/stdc++.h>
using namespace std;

// METHOD 1:- using STL next_permutation()
int findRank1(string str) {

	string orgstr = str; // store original string

	// Sort the string in lexicographically
	// ascending order
	sort(str.begin(), str.end());

	int i = 1;
	do {
		// check for the string
		if (str == orgstr)
			break;

		i++;
	} while (next_permutation(str.begin(), str.end()));

	//return rank
	return i;
}

//NOTE:- this method does not work under the duplicate char string
//METHOD 2:- using fact , some maths and for loop
//TIME COMP:- O(n)

//factorial func
int fact( int n) {
	if (n == 1) {
		return 1;
	}

	return n * fact(n - 1);
}

// main func
int findRank2(string str) {

	int rank = 1;
	int n = str.length();
	int mul = fact(n);
	int count[256] = {0};

	for (int i = 0 ; i < n ; i++) {
		count[str[i]]++;
	}

	for (int i = 1 ; i < 256; i++) {
		//cum sum
		count[i] = count[i] + count[i - 1];
	}

	for (int i = 0 ; i < n ; i++) {
		mul = mul / (n - i);
		rank = rank + count[str[i] - 1] * mul;

		for (int j = str[i] ; j < 256 ; j++) {
			count[j]--;
		}
	}

	return rank;
}


int main() {

	string str;
	cin >> str;

	cout << findRank2(str) << endl;

	return 0;
}