#include<bits/stdc++.h>
using namespace std;

// Time Comp:- O(n)
int main() {

	string str;
	cin >> str;

	int n = str.length();

	int count[256] = {0};

	for (int i = 0 ; i < n ; i++) {
		count[str[i]]++;
	}

	for (int i = 0 ; i < 256 ; i++) {
		if (count[i] > 1) {
			char ch = i;
			cout << ch;
		}
	}

	cout << endl;

	return 0;
}