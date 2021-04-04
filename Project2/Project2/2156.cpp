#include <iostream>
using namespace std;

int large(int x, int y) { return x > y ? x : y; }

int table[10002];
int ans[10002];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> table[i];
	}
	ans[1] = table[1];
	ans[2] = table[1] + table[2];

	for (int i = 3; i <= n; i++) {
		ans[i] = large(ans[i - 1], large(table[i] + ans[i - 2], table[i] + table[i - 1] + ans[i - 3]));
	}
	cout << ans[n];

}