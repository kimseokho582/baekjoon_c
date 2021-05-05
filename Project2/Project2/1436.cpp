#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int cnt = 0, ans = 0;

	while (cnt != n) {
		ans++;
		int tmp = ans;

		while (tmp) {
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			else {
				tmp /= 10;
			}
		}
	}
	cout << ans;
}