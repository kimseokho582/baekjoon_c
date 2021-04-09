#include <iostream>
#include <queue>
using namespace std;

int dir[6][2] = {
	{-2,-1},
	{-2,1},
	{0,-2},
	{0,2},
	{2,-1},
	{2,1}
};
int check[200][200] = { 0, };
int main() {
	int N; cin >> N;

	int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

	queue<pair<pair<int, int>, int>>q;
	q.push({ {r1,c1},0 });
	check[r1][c1] = 1;
	while (!q.empty()) {
		
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		check[x][y] = 1;

		if (x == r2 && y == c2) {
			cout << cnt;
			return 0;
		}

		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (check[nx][ny] != 1 && 0 <= nx && nx < N && 0 <= ny && ny < N) {
				check[nx][ny] = 1;
				q.push({ {nx,ny},cnt + 1 });
			}

		}
	}
	cout << -1;

}