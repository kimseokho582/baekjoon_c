#include <iostream>
using namespace std;

int gcd(int x, int y) {

	if (y == 0) {
		return x;
	}
	else {
		return gcd(y,x%y);
	}
}

int table[101];
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> table[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(table[i], table[j]);
			}
		}
		cout << ans << endl;
	}
}