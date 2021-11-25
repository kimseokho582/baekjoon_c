#include <iostream>
#include <algorithm>

using namespace std;
int table[100001];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int n; cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}
	sort(table, table + n,cmp);
	int large = table[0];
	for (int i = 1; i < n; i++) {
		if (table[i] * (i + 1) > large) {
			large = table[i] * (i + 1);
		}
	}
	cout << large;
}