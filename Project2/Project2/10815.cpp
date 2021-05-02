#include <iostream>
#include <algorithm>
using namespace std; 

int have[500001];
int table[500001];
int ans[500001];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> have[i];
	}
	sort(have, have + n);

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> table[i];
	}

	for (int i = 0; i < m; i++) {
		int r = n - 1, l = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (have[m] == table[i]) {
				ans[i] = 1;
				break;
			}
			if (have[m] > table[i]) {
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}

}