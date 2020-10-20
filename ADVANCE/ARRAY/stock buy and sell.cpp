// stock buy and sell :- maximize the profit
#include<bits/stdc++.h>
using namespace std;

// using recursion
// time:- O(n^n) , for one value of i , we call the maxProfit() function n times...therefore, for n itr , we call the maxProfit() func n^n times
//space:- O(n), depth of recursion is n
int maxProfit(int price[], int start, int end) {
	if (end <= start)
		return 0;

	int profit = 0;

	for (int i = start; i < end; i++) {
		for (int j = i + 1; j <= end; j++) {
			if (price[j] > price[i]) {
				int curr_profit = price[j] - price[i] + maxProfit(price, start, i - 1) + maxProfit(price, j + 1, end);
				profit = max(profit, curr_profit);
			}
		}
	}
	return profit;
}

//OPTIMISED
// time:- O(n)
// space:- O(1)
int maxProfitOP(int price[], int n) {
	int profit = 0;
	for (int i = 1; i < n; i++) {
		if (price[i] > price[i - 1]) {
			profit += price[i] - price[i - 1];
		}
	}
	return profit;
}

int main() {

	int arr[] = {1, 5, 3, 8, 12};

	cout << maxProfit(arr, 0, 4) << " " << maxProfitOP(arr, 5) << endl;

	return 0;
}