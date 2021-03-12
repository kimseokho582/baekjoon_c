#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
vector<pair<int, int>>table[100001];
int check[100001] = { 0, };
int n, restart, sum = 0;
void calc(int x, int val) {
	if (check[x] == 1) return;
	check[x] = 1;
	cout << "x: " << x << ", val: " << val << endl;
	if (sum < val) {
		sum = val;
		restart = x;
	}
	for (int i = 0; i < table[x].size(); i++) {
		calc(table[x][i].first, val + table[x][i].second);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		while (1) {
			int b; cin >> b;
			if (b == -1) {
				break;
			}
			int c; cin >> c;
			table[a].push_back({ b,c });
			table[b].push_back({ a,c });
		}
	}
	calc(1, 0);
	sum = 0;
	memset(check, 0, sizeof(check));
	calc(restart, 0);
	cout << sum;

}