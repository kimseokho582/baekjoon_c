#include <iostream>
using namespace std;
int N, K;
int table[11];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> table[i];
	int ans = 0;
	while (K) {
		ans += K / table[--N];
		K %= table[N];
	}
	cout << ans;
}