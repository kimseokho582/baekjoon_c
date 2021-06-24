#include <iostream>
#include <algorithm>
#define INF 999999999 
using namespace std;

int  table[101][101];
int n, m;

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			i == j ? table[i][j] = 0 : table[i][j] = INF;
		}
	}
}

int main() {
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		table[a][b] = 1;
		table[b][a] = 1;
	}

	for (int q = 1; q <= n; q++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				table[i][j] = min(table[i][j], table[i][q] + table[q][j]);
			}
		}
	}

	int ans = 5001, ansi;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += table[i][j];
		}
		if (sum < ans) {
			ans = sum;
			ansi = i;
		}
	}
	cout << ansi;
}
