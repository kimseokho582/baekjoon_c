#include <iostream>
#include <algorithm>
using namespace std;

int dir[3][2] = {
	{-1,-1},
	{-1,0},
	{0,-1}
};
int table[1000][1000];
int dp[1000][1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int large = 0;
			for (int k = 0; k < 3; k++) {
				int nx = i + dir[k][0], ny = j + dir[k][1];	
				if (0 <= nx && 0 <= ny) {
					large = max(large, dp[nx][ny]);
				}
	
			}
			dp[i][j] = table[i][j] +large;
		}
	}
	cout << dp[n - 1][m - 1];

}