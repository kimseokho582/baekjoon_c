#include <iostream>
#include <queue>

using namespace std;

int main() {
	int T; cin >> T;
	while (T-- > 0) {
		queue<int>table;
		int n; cin >> n;
		int ans = 0;
		table.push(0);
		while (!table.empty()) {
			int tmp = table.front();
			table.pop();
			if (tmp == n) {
				ans++;
			}
			if (tmp + 1 <= n) {
				table.push(tmp + 1);
			}
			if (tmp + 2 <= n) {
				table.push(tmp + 2);
			}
			if (tmp + 3 <= n) {
				table.push(tmp + 3);
			}
		}
		cout << ans<<endl;
	}
}

