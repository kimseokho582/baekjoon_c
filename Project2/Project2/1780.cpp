#include <iostream>

using namespace std; 

int table[2200][2200] = { 0, };
int ans[4] = { 0, };

void calc(int x, int y, int r) {
	int flag = 0;
	for (int i = x; i < x+r; i++) {
		for (int j = y; j < y+r; j++) {
			if (table[x][y] != table[i][j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)break;
	}

	if (flag == 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				calc(x + i * r/3, y + j * r/3, r / 3);
			}
		}
	}
	else {
		ans[table[x][y] + 1]++;
		return;
	}
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> table[i][j];
		}
	}

	calc(1, 1, n);
	for (int i = 0; i < 3; i++) {
		cout << ans[i] << endl;
	}

}
