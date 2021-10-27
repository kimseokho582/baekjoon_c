#include <iostream>
using namespace std;

int n, k;
int table[101];
int DP[10001];

int main() {

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> table[i];


	DP[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = table[i]; j <= k; j++) {
			DP[j] = DP[j] + DP[j - table[i]];
		}
	}
	cout << DP[k];
}
