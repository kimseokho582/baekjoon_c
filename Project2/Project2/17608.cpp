#include <iostream>
using namespace std;

int table[100001];

int  main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}
	int check = table[n - 1];
	int ans = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (check < table[i]) {
			ans++;
			check = table[i];
		}
	}
	cout << ans;
}