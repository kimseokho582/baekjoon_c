#include <iostream>
#include <cmath>
using namespace std;

int table[2][6];

int main() {
	int n, m; cin >> n >> m;
	float ans = 0.0;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		table[a][b-1]++;
	}

	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			ans += ceil(table[i][j] /float(m));	
		}
	}
	cout << ans;
}