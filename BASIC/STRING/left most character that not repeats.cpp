#include<bits/stdc++.h>
using namespace std;

//METHOD 1:- using count array and 2 itrn
//Time Comp:- O(n)
int nonfirstReapeating1(string str) {
	int n = str.length();
	int count[256] = {0};

	for (int i = 0 ; i < n ; i++) {
		count[str[i]]++;
	}

	for (int i = 0 ; i < n ; i++) {
		if (count[str[i]] == 1) {
			return i;
		}
	}

	return -1;
}

//METHOD 2:- using count array and 1 itrn
//TIME COMP:- O(n)
int nonfirstReapeating2(string str) {
	int res = INT_MAX;
	int fi[256];

	memset(fi, -1, sizeof(fi));	//initialize whole array by -1

	for (int i = 0 ; i < str.length(); i++) {
		if (fi[str[i]] == -1) {
			//character appears first time
			fi[str[i]] = i;
		}
		else {
			//it appears more than 1 time than set the value to -2
			fi[str[i]] = -2;
		}

	}

	for (int i = 0 ; i < 256 ; i++) {
		if (fi[i] >= 0)
			//find min index
			res =  min(res, fi[i]);
	}
	return (res == INT_MAX) ? -1 : res;
}



int main() {

	string str ;
	cin >> str;

	cout << nonfirstReapeating2(str) << endl;

	return 0;
}