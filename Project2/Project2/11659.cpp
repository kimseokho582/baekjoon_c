#include <iostream>
using namespace std;

int table[100001] = { 0, };

int  main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		table[i] = tmp + table[i - 1];
	}
	while (m--) {
		int a, b; cin >> a >> b;
		cout << table[b] - table[a - 1] << "\n";
	}
}