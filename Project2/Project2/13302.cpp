#include <iostream>
#include <algorithm>

using namespace std;
#define INF 999999999
int n, m, table[102][102], nov[102];


int calc(int d,int c) {

	if (d > n)return 0;
	if (table[d][c] != INF) return table[d][c];
	if (nov[d] == 1) {
		table[d][c] = calc(d + 1, c);
		return table[d][c];
	}

	table[d][c] = min(table[d][c], calc(d + 1, c) + 10000);
	table[d][c] = min(table[d][c], calc(d + 3, c+1) + 25000);
	table[d][c] = min(table[d][c], calc(d + 5, c+2) + 37000);
	if (c >= 3) {
		table[d][c] = min(table[d][c], calc(d + 1, c - 3));
	}
	return table[d][c];
}

int main() {
	cin >> n >> m;
	while (m--) {
		int tmp; cin >> tmp;
		nov[tmp] = 1;
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			table[i][j] = INF;
		}
	}
	cout<<calc(1, 0);
}