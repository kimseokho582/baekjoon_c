#include <iostream>
using namespace std;

int check[2010][2010] = { 0, };

int gcd(int x, int y) {
	int tmp;
	while (y != 0) {
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

int main() {
	int d1, d2; cin >> d1 >> d2;
	int ans = 0;
	for (int i = d1; i <= d2; i++) {
		for (int j = 1; j <= i; j++) {
			int tmp = gcd(i, j);
			if (!check[i / tmp][j / tmp]) {
				check[i / tmp][j / tmp] = 1;
				ans++;
			}
		}
	}
	cout << ans;
}


