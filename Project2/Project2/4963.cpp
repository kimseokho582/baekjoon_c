#include <iostream>
#include <queue>
using namespace std;

int n, m;
int table[50][50] = { 0, };
int check[50][50] = { 0, };

int dir[8][2] = {
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,-1},
	{0,1},
	{1,-1},
	{1,0},
	{1,1}
};

void find(int x,int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	check[x][y] = 1;

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = xx + dir[i][0];
			int ny = yy + dir[i][1];
			if (0 <= nx && nx < m && 0 <= ny && ny < n&&table[nx][ny]==1&&check[nx][ny]==0) {
				check[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}

	

}
void clear(int (*a)[50]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (cin >> n >> m) {
		if (n == 0 && m == 0)break;

		
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> table[i][j];
			}
		}
		clear(check);
	
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (table[i][j] == 1 && check[i][j] == 0) {
					ans++;
					find(i, j);
				}
			}
		}
		cout <<ans<< '\n';
	}

}