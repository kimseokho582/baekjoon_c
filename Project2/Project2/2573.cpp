#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};
int table[300][300];
int calc[300][300] = { 0,0 };
int n, m,ans;
int cnt = 0;

int Dcheck() {
	int check[300][300] = { 0, };
	queue<pair<int, int >>q;
	int tmp = 0;
	int x = -1, y = 0;
	for (int i = 0; i < n; i++) {
		if (x != -1)break;
		for (int j = 0; j < m; j++) {
			if (table[i][j] != 0) {
				x = i;
				y = j;
			}
		}
	}
	if (x == -1)return -1;
	q.push({ x,y });
	check[x][y] = 1;
	tmp++;
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dir[i][0], ny = yy + dir[i][1];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && check[nx][ny] == 0&&table[nx][ny]!=0) {
				check[nx][ny] = 1;
				tmp++;
				q.push({ nx,ny });
			}
		}
	}
	ans++;
	if (cnt != tmp) {
		return 1;
	}
	else {
		cnt = 0;
		return 0;

	}

}

void Mcheck(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && table[nx][ny] == 0) {
			calc[x][y]++;
		}
	}

}
void Melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			table[i][j] -= calc[i][j];

			if (table[i][j] <= 0)table[i][j] = 0;
			if (table[i][j] != 0) {
				cnt++;
			}
			calc[i][j] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int a = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
		}
	}
	do {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (table[i][j] != 0) {
					Mcheck(i, j);
				}
			}
		}
		Melt();
		a = Dcheck();
		if (a == -1) {
			cout << 0;
		}
		else if (a == 1) {
			cout << ans;
			break;
		}
	} while (a != -1);

}