#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (1) {
			if (tmp % 5 == 0) {
				ans++;
				tmp /= 5;
			}
			else {
				break;
			}
		}
	}
	cout << ans;
}