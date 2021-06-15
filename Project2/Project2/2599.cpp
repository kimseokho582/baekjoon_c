#include <iostream>
using namespace std;

int table[3][2];
int ans[3][2];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> table[i][j];
		}
	}
	
	for (int i = 0; i <= table[0][0]; i++) {
		ans[0][0] = i;
		ans[0][1] = table[0][0] - ans[0][0];
		ans[1][0] = n - table[2][0] - table[2][1] - ans[0][0];
		ans[1][1] = table[1][0] - ans[1][0];
		ans[2][0] = table[0][1] - ans[1][0];
		ans[2][1] = table[2][0] - ans[2][0];
		if ((ans[0][0] >= 0) && (ans[1][0] >= 0) && (ans[2][0] >= 0) &&
			(ans[0][1] >= 0) && (ans[1][1] >= 0) && (ans[2][1] >= 0)) {
			cout << 1 << endl;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 2; j++) {
					cout << ans[i][j] << " ";
				}cout << endl;
			}
			return 0;

		}
	}
	cout << 0;
}