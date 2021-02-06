#include <iostream>

using namespace std;

int table[51][51] = { 0, };
int check[51][51] = { 0, };

int dir[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};
int M, N, K,times,cnt;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			table[j][i] = 0;
			check[j][i] = 0;
			cnt = 0;
		}
	}
}
void dfs(int x, int y) {
	check[x][y] = 1;
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dir[i][0];
		ny = y + dir[i][1];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
			continue;
		}
		if (table[nx][ny] == 1 && check[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
		
}
int main() {
	
	scanf_s("%d", &times);
	while (times-- > 0) {
		init();
		scanf_s("%d %d %d",&M, &N,&K);
		while (K-- > 0) {
			int x, y;
			scanf_s("%d %d", &x, &y);
			table[x][y]=1;
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (table[j][i] == 1 && check[j][i] == 0) {
					dfs(j, i);
					cnt++;
				}
			}
		}
		cout << cnt<<endl;
	}
	
}