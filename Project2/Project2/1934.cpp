#include <iostream>
using namespace std;
/*int gcd(int x, int y) {
	if (x == 0) {
		return y;
	}	
	gcd(y % x, x);
}*/

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
	int n; cin >> n;
	while (n--) {
		int x, y; cin >> x >> y;
		cout << x * y / gcd(x, y)<<endl;
	}
	return 0;
}