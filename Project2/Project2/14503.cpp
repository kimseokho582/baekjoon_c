#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int table[31][31];
int n, m, r, c, d;

int dir[4][3] = {
	{1,0,2},
	{0,1,1},
	{-1,0,0},
	{0,-1,3},
};
int answer = 0;

void calc (int nr, int nc, int nd) {
	if (table[nr][nc] == 0) {
		table[nr][nc] = 2;
		answer++;
	}
	for (int i = 3-nd; i < 3-nd + 4; i++) {
		int nnr = nr + dir[i % 4][0], nnc = nc + dir[i % 4][1];
		if (nnr < 0 || nnc < 0 || nnr >= n || nnc >= m) {
			continue;
		}
		if (table[nnr][nnc] == 0) {

			calc(nnr, nnc, dir[i % 4][2]);
		}
	}

	int bd = (3 - nd + 1) % 4;
	int br = nr + dir[bd][0];
	int bc = nc + dir[bd][1];
	if (table[br][bc] == 1) {
		cout << answer;
		exit(0);
	}
	if (0<=br&&br<n&&0<=bc&&bc<m) {	
	calc(br, bc, nd);
	}

}

int main() {
	 cin >> n >> m >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
		}
	}
	
	calc(r, c, d);
}