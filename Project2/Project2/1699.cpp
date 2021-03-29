#include <iostream>
using namespace std;
int table[100002];

int small(int x, int y) {
	if (x > y) return y;
	else return x;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <=n; i++) {
		table[i] = i;
		for (int j = 1; j*j <= i; j++) {
			table[i] = small(table[i], table[i - j * j] + 1);
		}
	}
	cout << table[n];
}