#include <iostream>
#include <queue>
using namespace std;

int check[100][100] = { 0, };
int answer = 0;
int dir[4][2] = {
	{1,0},{-1,0},{0,1},{0,-1}
};

void calc(vector<vector<int> > maps, int n, int m) {
	queue < pair<int, pair<int, int>>>q;
	q.push({ 1,{0,0} });
	check[0][0] = 1;
	while (!q.empty()) {
		;
		int x = q.front().second.first, y = q.front().second.second;
		int cnt = q.front().first;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			answer = cnt;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0], ny = y + dir[i][1], ncnt = cnt + 1;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && maps[nx][ny] && !check[nx][ny]) {
				q.push({ ncnt,{nx,ny} });
				check[nx][ny] = 1;
			}
		}

	}
	answer = -1;
	return;

}

int solution(vector<vector<int> > maps)
{
	calc(maps, maps.size(), maps[0].size());
	return answer;
}