#include<bits/stdc++.h>
using namespace std;

// subsets and subsequences are same for the string


void subset(string str, string curr = " ", int index = 0) {

	if (index == str.length()) {
		cout << curr << " ";
		return;
	}

	subset(str, curr, index + 1); //without adding current character
	subset(str, curr + str[index], index + 1); //with adding current character
}

int main() {

	string str = "ABC";
	// cin>>str;

	subset(str);
	cout << endl;

	return 0;
}