#include<bits/stdc++.h>
using namespace std;

//METHOD 1:- using nested for loop
//Time Comp:- O(n^2)
int firstReapeating1(string str) {
	int n = str.length();

	for (int i = 0 ; i < n ; i++) {
		for (int j = i + 1; j < n ; j++) {
			if (str[i] == str[j]) {
				return i;
			}
		}
	}

	return -1;
}

//METHOD 2:- using count array
//TIME COMP:- O(n)
int firstReapeating2(string str) {
	int res = INT_MAX;
	int fi[256];

	memset(fi, -1, sizeof(fi));	//initialize whole array by -1

	for (int i = 0 ; i < str.length(); i++) {
		if (fi[str[i]] == -1) {
			//character appears first time
			fi[str[i]] = i;
		}
		else {
			//it appears more than 1 time than find its first index of appearance which is its min index
			//which is stored in fi
			res = min(res, fi[str[i]]);
		}

	}
	return (res == INT_MAX) ? -1 : res;
}

//METHOD 2:- using count array without using min in else condition
//TIME COMP:- O(n)
int firstReapeating3(string str) {
	int res = INT_MAX;
	int fi[256];

	memset(fi, -1, sizeof(fi));	//initialize whole array by -1

	for (int i = str.length() - 1 ; i >= 0; i--) {
		if (fi[str[i]] == -1) {
			//character appears first time
			fi[str[i]] = i;
		}
		else {
			//it appears more than 1 time than find its first index of appearance which is its min index
			//which is stored in fi
			res = i;
		}

	}
	return (res == INT_MAX) ? -1 : res;
}


int main() {

	string str;
	cin >> str;

	cout << firstReapeating3(str) << endl;

	return 0;
}