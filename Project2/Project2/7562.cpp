#include <iostream>
#include <queue>
using namespace std;
int table[300][300];
int check[300][300];
queue<pair<pair<int, int>,int>>q;
int moveD[8][2] = {
	{-2,-1},
	{-2,1},
	{-1,-2},
	{-1,2},
	{2,-1},
	{2,1},
	{1,-2},
	{1,2}
};


void clearQueue(queue<pair<pair<int, int>, int>>& q)
{
	queue<pair<pair<int, int>, int>> empty;
	swap(q, empty);
}
void init(int(*a)[300], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		init(check, n);
		int srcx, srcy, dstx, dsty; cin >> srcx >> srcy >> dstx >> dsty;

		if (srcx == dstx && srcy == dsty) {
			cout << 0 << endl;
			continue;
		}
		q.push({ { srcx,srcy },0 });
		check[srcx][srcy] = 1;
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int val = q.front().second;

			q.pop();
			if (x == dstx && y == dsty) {
				cout << val<< endl;
				clearQueue(q);
				break;
			}
			for (int i = 0; i < 8; i++) {
				int nx = x + moveD[i][0];
				int ny = y + moveD[i][1];
				if (0 <= nx && nx < n && 0 <= ny && ny < n && check[nx][ny] == 0) {
					check[nx][ny] = 1;
					q.push({ { nx,ny },val+1 });
				}
			}
		}
		
	}
}