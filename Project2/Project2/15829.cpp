#include <iostream>

#define MOD 1234567891
using namespace std;

int main() {

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	long long answer = 0, n; cin >> n;
	long long num = 1;
	for (int i = 0; i < n; i++) {
		char w; cin >> w;

		answer +=((w - 'a'+1)*num) % MOD;
		num *= 31;
		num %= MOD;
	}
		cout << answer % MOD << endl;
}