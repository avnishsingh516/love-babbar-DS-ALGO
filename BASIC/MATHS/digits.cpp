//find the no of digits
#include<bits/stdc++.h>
using namespace std;

//iterative sol
int itrDigit(int n) {
	int count = 0;
	while (n != 0) {
		n = n / 10;
		++count;
	}
	return count;
}

//recursive sol
int recDigit(int n) {
	if (n == 0) {
		return 0;
	}

	return 1 + recDigit(n / 10);
}

//log sol
int countDigit(int n) {
	return floor(log10(n) + 1);
}

int main() {

	int n = 12340;
	cout << itrDigit(n) << " " << recDigit(n) << " " << countDigit(n) << endl;
	return 0;
}