#include <iostream>
#include <queue>

using namespace std;

int table[1000001];
int main() {
	int N; cin >> N;
	table[1] = 0;

	for (int i = 2; i <= N; i++) {
		table[i] = table[i - 1] + 1;
		if (!(i % 2)) {
			table[i] = min(table[i], table[i / 2] +1);
		}
		if (!(i % 3)) {
			table[i] = min(table[i], table[i / 3] + 1);
		}
	}
	cout << table[N];
}