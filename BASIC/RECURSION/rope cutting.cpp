#include<bits/stdc++.h>
using namespace std;

// TIME COMP:- O(3^n)
int maxCut(int n, int a, int b, int c) {

	if (n < 0) return -1;
	if (n == 0) return 0;

	int res = max (maxCut(n - a, a, b, c), max( maxCut(n - b, a, b, c), maxCut(n - c, a, b, c) ));

	if (res == -1) return -1; //edge case:- where we cant cut the rope equally

	return (res + 1);
}

int main() {

	int n = 5 , a = 4, b = 2, c = 6;
	// cin>>n>>a>>b>>c;

	cout << maxCut(n, a, b, c) << endl;

	return 0;
}