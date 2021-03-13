#include <iostream>
#include <algorithm>
using namespace std;
#define INF 999999999

int table[101][101];
int main() {
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				table[i][j] = 0;
			}
			else {
				table[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (table[a][b] != INF) {
			table[a][b]=min(table[a][b], c);
		}
		else {
			table[a][b] = c;
		}
	}

	for (int q = 1; q <= n; q++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				table[i][j] = min(table[i][j], table[i][q] + table[q][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (table[i][j] == INF)table[i][j] = 0;
			cout << table[i][j] << " ";
		}cout << endl;
	}
}