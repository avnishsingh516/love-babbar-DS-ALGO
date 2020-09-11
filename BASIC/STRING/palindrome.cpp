#include<bits/stdc++.h>
using namespace std;

bool palindrome(string str) {

	int n = str.length();

	for (int i = 0 ; i < n / 2 ; i++) {
		if (str[i] != str[n - i - 1]) {
			return false;
		}
	}

	return true;
}

int main() {

	string str ;
	cin >> str;

	palindrome(str) ? cout << "YES" : cout << "NO";
	cout << endl;

	return 0;

}