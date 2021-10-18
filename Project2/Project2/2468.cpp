#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int table[101][101];
int dir[4][2] = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};
int main() {
	int n; cin >> n;
	int top = 0;
	int rst = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
			top = max(table[i][j], top);
		}
	}
	for (int k = 0; k < top; k++) {
		int visited[100][100] = { 0, };
		queue<pair<int,int>>q;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (table[i][j] - k > 0 && visited[i][j] != 1) {
					cnt++;
					q.push({ i,j });
					visited[i][j] = 1;
					while (!q.empty()) {
						int ii = q.front().first;
						int jj = q.front().second;
						q.pop();
						for (int a = 0; a < 4; a++) {
							int ni = ii + dir[a][0];
							int nj = jj + dir[a][1];
							if (0 <= ni && ni < n && 0 <= nj && nj < n) {
								if (table[ni][nj] - k > 0 && visited[ni][nj] != 1) {
									q.push({ ni,nj });
									visited[ni][nj] = 1;
								}
							}
						}
					}
				}
			}
		}
		rst = max(rst,cnt);
	}
	cout << rst;
}