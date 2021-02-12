#include <iostream>
#include <queue>
using namespace std;

int table[1001][1001];
queue<pair< int, int>>check;
int ans = 0;

int main() {

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int M, N; cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> table[i][j];
			if (table[i][j] == 1) {
				check.push(make_pair(i, j));
			}
		}
	}
	int x, y;
	while (!check.empty()) {
		int cnt = check.size();
		for (int i = 0; i < cnt; i++) {
			x = check.front().first; y = check.front().second;
			check.pop();
			
				if (x-1>=0&&table[x-1][y]==0) {
					table[x - 1][y] = 1;
					check.push(make_pair(x-1, y));
				}

				if (x+1<N&&table[x+1][y] == 0) {
					table[x +1][y] = 1;
					check.push(make_pair(x + 1, y));

				}

				if (y-1>=0&&table[x][y-1] == 0) {
					table[x ][y-1] = 1;
					check.push(make_pair(x , y-1));

				}

				if (y+1<M&&table[x][y+1] == 0) {
					table[x ][y+1] = 1;
					check.push(make_pair(x , y+1));

				}
			
		}
		ans++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (table[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << ans - 1;
}