#include <iostream>
#include <algorithm>
using namespace std;

int table[2][100001];
int ans[2][100001];

int main() {
	int T; cin >> T;

	while (T--) {

		int n; cin >> n;
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> table[i][j];
			}
		}
		ans[0][0] = table[0][0];
		ans[1][0] = table[1][0];
		ans[0][1] = ans[1][0] + table[0][1];
		ans[1][1] = ans[0][0] + table[1][1];

		for (int i = 2; i < n; i++) {
			ans[0][i] = table[0][i] + max(ans[1][i - 1], ans[1][i - 2]);
			ans[1][i] = table[1][i] + max(ans[0][i - 1], ans[0][i - 2]);
		}
		cout << max(ans[0][n - 1], ans[1][n - 1])<<endl;


	}
}