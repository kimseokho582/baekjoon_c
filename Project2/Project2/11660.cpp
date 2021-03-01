#include <iostream>

using namespace std;

int table[1025][1025];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp; cin >> tmp;
			table[i + 1][j + 1] = tmp + table[i + 1][j] + table[i][j + 1] - table[i][j];
		}
	}
	while (M--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << table[x2][y2] - table[x1 - 1][y2] - table[x2][y1 - 1] + table[x1 - 1][y1 - 1] << "\n";
	}
	
}