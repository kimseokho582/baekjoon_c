#include <iostream>
using namespace std;

int main() {
	long long table[2][10];
	long long N; cin >> N;
	
	for (int i = 0; i < 10; i++) {
		table[0][i] = i+1;
	}
	table[1][0] = 1;

	for (int i = 1; i < N ; i++) {
		for (int j = 1; j < 10; j++) {
			i % 2 == 1 ? table[1][j] = (table[1][j - 1] + table[0][j]) % 10007 : table[0][j] = (table[0][j - 1] + table[1][j]) % 10007;
		}
	}
	N%2==1? cout << table[0][9] % 10007: cout << table[1][9] % 10007;
}

