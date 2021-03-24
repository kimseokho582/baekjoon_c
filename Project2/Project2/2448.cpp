#include <iostream>

using namespace std;

char table[3*1024+1][3*2048];

void draw(int x, int y) {
	table[x][y] = '*';
	
	table[x + 1][y - 1] = '*';
	table[x + 1][y + 1] = '*';

	for (int i = 0; i < 5; i++) {
		table[x + 2][y - 2 + i] = '*';
	}
}

void srh(int v, int x, int y) {
	if (v == 3) {
		draw(x, y);
		return;
	}
	srh( v/ 2, x, y);
	srh(v / 2, x + v / 2, y - v / 2);
	srh(v / 2, x + v / 2, y + v / 2);
}

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			table[i][j] = ' ';
		}
	}
	srh(N, 0, N - 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << table[i][j];
		}cout << endl;
	}
}