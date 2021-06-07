#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int n, k,table[5001],ans=0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}
	sort(table, table + n,cmp);
	for (int i = 0; i < k; i++) {
		ans += table[i] - i;
	}cout << ans;
}