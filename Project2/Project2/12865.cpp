#include <iostream>
#include <algorithm>
using namespace std;
int table[101][2]; int dp[102][100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K; cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> table[i][0] >> table[i][1];
	}
	for (int i = 1; i <= N; i++) {
		int w = table[i][0], v = table[i][1];
		for (int j = 0; j <= K; j++) {
			if (j < table[i][0])dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
			}
		}
	}cout << dp[N][K];
}