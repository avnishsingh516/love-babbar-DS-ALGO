#include<bits/stdc++.h>
using namespace std;

int fun(int n) {

	if (n < 10) {
		//only single digit left
		return n;
	}

	return fun(n / 10) + n % 10;
}

int main() {

	int n = 253;
	// cin>>n;

	cout << fun(n) << endl;

	return 0;
}