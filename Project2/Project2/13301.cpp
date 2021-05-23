#include <iostream>

using namespace std;

long long f[82];


int main() {
	int n; cin >> n;
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	cout << 4 * f[n] + 2 * f[n - 1];
}