#include<bits/stdc++.h>
using namespace std;

// METHOD 1:- using stack stl
void reverseWords1(string str)
{
	stack<char> st;

	// Traverse given string and push all characters
	// to stack until we see a space.
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] != ' ')
			st.push(str[i]);

		// When we see a space, we print contents
		// of stack.
		else {
			while (st.empty() == false) {
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
	}

	// Since there may not be space after
	// last word.
	while (st.empty() == false) {
		cout << st.top();
		st.pop();
	}
}


//METHOD 2:- using stringstream
void reverseWords2(string str)
{
	// word variable to store word
	string word;

	// making a string stream
	stringstream iss(str);

	// Read and print each word.
	while (iss >> word) {
		reverse(word.begin(), word.end());
		cout << word << " ";
	}
}

int main()
{
	string s = "GeeksforGeeks is good to learn";
	reverseWords1(s);
	cout << endl;
	reverseWords2(s);
	cout << endl;
	return 0;
}
