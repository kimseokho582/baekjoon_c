#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int table[1000][1000];
int check[1000][1000][2];
int dir[4][2] = {
	{-1,0},{1,0},{0,1},{0,-1}
};


int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			int num = tmp[j] - '0';
			table[i][j] = num;
		}
	}

	queue<tuple<int, int, int, int>>q;
	q.push({ 0,0,1,0 });
	check[0][0][0] = 1;
	while (!q.empty()) {

		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int val = get<2>(q.front());
		int brk = get<3>(q.front());

		if (x == N - 1 && y == M - 1) {
			cout << val;
			return 0;
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (table[nx][ny] == 1 && brk == 0) {
					check[nx][ny][brk + 1] = 1;
					q.push({ nx ,ny,val + 1,brk + 1 });
				}
				else if (table[nx][ny] == 0 && check[nx][ny][brk] == 0) {
					check[nx][ny][brk] = 1;
					q.push({ nx ,ny,val + 1,brk });
				}

			}
		}
	}
	cout << -1 << endl;
}