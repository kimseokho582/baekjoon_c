#include <iostream>
#include <cmath>
using namespace std;

int gcd(int x, int y) {

	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}

int  main() {
	int dis, bro, ans = 0;
	int n, m; cin >> n >> m>>bro;
	ans = abs(m - bro);
	for (int i = 1; i < n; i++) {
		int bro; cin >> bro;
		dis = abs(m - bro);
		ans = gcd(ans, dis);
	}
	cout << ans;
}