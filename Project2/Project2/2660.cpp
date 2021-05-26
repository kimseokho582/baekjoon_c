#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 999999999

int table[50][50];
int tmp[51];
vector<int>ansArr;
int ans=INF;

int  main() {
	int n; cin >> n;
	int a, b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)table[i][j] = 0;
			else table[i][j] = INF;
		}
	}

	while (cin >> a >> b) {
		if (a == -1 && b == -1)break;
		table[a][b] = 1;
		table[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			tmp[i] = max(tmp[i], table[i][j]);
		}
		ans = min(ans, tmp[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (ans == tmp[i]) {
			ansArr.push_back(i);
		}
	}
	cout << ans << " " << ansArr.size() << endl;
	for (int x : ansArr)cout << x << " ";
}