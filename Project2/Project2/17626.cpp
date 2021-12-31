#include <iostream>
#include <algorithm>
using namespace std;

int table[50001];

int main() {
	int n; cin >> n;
	table[0] = 0;
	table[1] = 1;
	for (int i = 2; i <= n; i++) {
		int tmp = 50001;
		for (int j = 1; j*j <= i; j++) {
			tmp = min(tmp, table[i - j * j] + 1);
		}
		table[i] = tmp;
	}
	cout << table[n];
}