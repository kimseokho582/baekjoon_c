#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int table[102];

int main() {
	int n; cin >> n;
	table[0] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> table[i];
	}
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		if (a == 1) {
			for (int i = 1; i * b <= n; i++) {
				table[b * i] = !table[b * i];
			}
		}
		else if (a == 2) {
			table[b] = !table[b];
			for (int i = 1; table[b - i] == table[b + i]; i++) {
				if (b - i<1 || b + i>n)break;
				table[b-i] = !table[b-i];
				table[b+i] = !table[b+i];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << table[i] << " ";
		if (i % 20 == 0&&i!=0) {
			cout << endl;
		}
	}
}