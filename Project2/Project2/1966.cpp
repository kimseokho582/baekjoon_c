#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		queue<pair<int, int>>q;
		vector<int>v;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			v.push_back(x);
			if (i == m) {
				q.push({ x,1 });
			}
			else {
				q.push({ x,0 });
			}
		}
		sort(v.begin(), v.end(),cmp);
		
		int idx = 0;
		while (1) {
			if (q.front().first >= v[idx]) {
				if (q.front().second == 1) {
					cout << idx+1 << endl;
					break;
				}
				else {
					q.pop();
					idx++;
				}
			}
			else {
				q.push({ q.front().first,q.front().second });
				q.pop();
			}
		}

	}
}