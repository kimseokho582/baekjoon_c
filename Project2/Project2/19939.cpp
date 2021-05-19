#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
	int num = 0;
	for (int i = 0; i <= m; i++) {
		num += i;
	}
	if (num > n) {
		cout << -1;
		return 0;
	}
	else {
		if ((n - num) % m == 0) {
			cout << m - 1;
		}
		else {
			cout << m;
		}
	}
}