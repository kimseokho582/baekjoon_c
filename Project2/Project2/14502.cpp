#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int table[8][8];
int tmp[8][8];
int ans = 0;
vector<pair<int, int>>virusIdx;
int N, M;
int dir[4][2] = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

void makeTmp(int a[8][8], int b[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void spread() {
	queue<pair<int, int>>spreadV;
	int spreadtmp[8][8];
	makeTmp(spreadtmp, tmp);
	for (int i = 0; i < virusIdx.size(); i++) {
		spreadV.push({ virusIdx[i].first ,virusIdx[i].second });
	}

	while (!spreadV.empty()) {
		int x = spreadV.front().first;
		int y = spreadV.front().second;
		spreadV.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && spreadtmp[nx][ny] == 0) {
				spreadtmp[nx][ny] = 2;
				spreadV.push({ nx,ny });
			}
		}
	}
	int val = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (spreadtmp[i][j] == 0) {
				val++;
			}
		}
	}
	ans = max(ans,val );

}

void makeW(int cnt) {
	if (cnt == 3) {
		spread();
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				makeW(cnt+1);
				tmp[i][j] = 0;
			}
		}
	}
}



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> table[i][j];
			if (table[i][j] == 2) {
				virusIdx.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (table[i][j] == 0) {
				makeTmp(tmp, table);
				tmp[i][j] = 1;
				makeW(1);
				tmp[i][j] = 0;
			}
		}
	}

	cout << ans;
}