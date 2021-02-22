#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	int table[501][501];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> table[i][j];
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)table[i][j] += table[i - 1][j];
			else if (j == i)table[i][j] += table[i - 1][j - 1];
			else {
				table[i][j] += max(table[i - 1][j - 1], table[i - 1][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(table[n][i], ans);
	}
	cout << ans;
}
