#include <iostream>
using namespace std;

long long table[2][202];

int main() {
	int N, K; cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		table[0][i] = 1;
	}
	table[1][0] = 1;
	for (int i = 1; i < K ; i++) {
		for (int j = 1; j <= N; j++) {
			i % 2 == 1 ? table[1][j] = (table[1][j - 1] + table[0][j]) % 1000000000 : table[0][j] = (table[0][j - 1] + table[1][j]) % 1000000000;
		}

	}
	K % 2 == 1 ? cout << table[0][N] % 1000000000 : cout << table[1][N] % 1000000000;
}
