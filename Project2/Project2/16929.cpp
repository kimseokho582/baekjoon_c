#include <iostream>
using namespace std;

int dir[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
char table[51][51];
int check[51][51];
int n, m;

void calc(int x, int y, int cnt, int nodir) {


	if (cnt >= 4 && check[x][y]) {
		cout << "Yes";
		exit(0);
	}

	check[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		if (nodir == i)continue;
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (0 <= nx && nx < n && 0 <= ny && ny < m && table[x][y] == table[nx][ny]) {
			calc(nx, ny, cnt + 1, (i + 2) % 4);
			check[nx][ny] = 0;
		}
	}

	return;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			calc(i, j, 0, -1);
			check[i][j] = 0;
		}
	}
	cout << "No";
}