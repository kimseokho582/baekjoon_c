#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<pair<int, int>>table;
int n,ans=0;
int calc(int idx) {
	int num = table[idx].first, color = table[idx].second;
	int ret = 999999;
	for (int i = 0; i < n; i++) {
		if (i == idx)continue;
		if (table[i].second == color) {
			ret = min(ret, abs(table[i].first - num));
		}
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		table.push_back({ a,b });
	}
	for (int i = 0; i < n; i++) {
		ans+=calc(i);
	}
	cout << ans;
}