#include <iostream>
using namespace std;

int large(int x, int y) { return x > y ? x : y; }

int table[1001];
int calc[1001];
int ans = 0;
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> table[i];
		calc[i] = table[i];
		for (int j = 0; j < i; j++) {
			if (table[i] > table[j] && calc[i] < calc[j] + table[i])
				calc[i] = calc[j] + table[i];
		}
		ans = large(ans, calc[i]);
	}
	cout << ans;
}
