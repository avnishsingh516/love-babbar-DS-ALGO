#include<bits/stdc++.h>
using namespace std;


//**********************    METHOD 1:- using sorting    *********************************
// TIME COMP:- O(nLogn)
bool isAnagram1(string str, string pattern) {

	// if two strings length are not equal then it is not isAnagram
	if (str.length() != pattern.length()) {
		return 0;
	}

	//sort the string
	sort(str.begin(), str.end());
	sort(pattern.begin(), pattern.end());


	for (int i = 0 ; i < str.length() ; i++) {
		if (str[i] != pattern[i]) {
			return 0;
		}
	}

	return 1;
}


//**********************    METHOD 2:- counting characters using two array    *********************************
// TIME COMP:- O(n)
bool isAnagram2(string str, string pattern) {

	// if two strings length are not equal then it is not isAnagram
	if (str.length() != pattern.length()) {
		return 0;
	}

	//using 2 counting array
	int count1[256] = {0};
	int count2[256] = {0};

	for (int i = 0 ; i < str.length(); i++) {
		count1[str[i]]++;
	}

	for (int i = 0 ; i < pattern.length() ; i++) {
		count2[pattern[i]]++;
	}

	for (int i = 0 ; i < 256 ; i++) {
		if (count1[i] != count2[i]) {
			return 0;
		}
	}

	return 1;
}


//**********************    METHOD 3:- counting characters using one array    *********************************
// TIME COMP:- O(n)
bool isAnagram3(string str, string pattern) {

	// if two strings length are not equal then it is not isAnagram
	if (str.length() != pattern.length()) {
		return 0;
	}

	//using 1 counting array
	int count[256] = {0};

	for (int i = 0 ; i < str.length(); i++) {
		count[str[i]]++;
	}

	for (int i = 0 ; i < pattern.length() ; i++) {
		count[pattern[i]]--;
	}

	for (int i = 0 ; i < 256 ; i++) {
		if (count[i] != 0) {
			return 0;
		}
	}

	return 1;
}

int main() {

	string str, pattern;
	cin >> str >> pattern;

	if (isAnagram2(str, pattern))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;



	return 0;
}