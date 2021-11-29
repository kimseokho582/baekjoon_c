#include <iostream>

using namespace std;

long long table[100];

int main() {
	int n; cin >> n;
	table[1] = 1;
	table[2] = 1;
	for (int i = 3; i <= n; i++) {
		table[i] = table[i - 1] + table[i - 2];
	}
	cout << table[n];
}