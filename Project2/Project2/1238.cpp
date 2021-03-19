#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define INF 99999999
using namespace std;

vector<pair<int, int>>table[1001];
vector<pair<int, int>>retable[1001];
int dis[1001];
int redis[1001];
void srh(int x) {
	dis[x] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,x }); //거리, 위치
	while (!pq.empty()) {
		int d = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dis[cur] < d) continue;

		for (int i = 0; i < table[cur].size(); i++) {
			int nd = d + table[cur][i].second;
			int next = table[cur][i].first;

			if (nd < dis[next]) {
				dis[next] = nd;
				pq.push({ -nd,next });
			}
		}
	}
}

void resrh(int x) {
	redis[x] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,x }); //거리, 위치
	while (!pq.empty()) {
		int d = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (redis[cur] < d) continue;

		for (int i = 0; i < retable[cur].size(); i++) {
			int nd = d + retable[cur][i].second;
			int next = retable[cur][i].first;

			if (nd < redis[next]) {
				redis[next] = nd;
				pq.push({ -nd,next });
			}
		}
	}
}

int main() {
	int N, M, X; cin >> N >> M >> X;

	for (int i = 1; i <= N; i++) dis[i] = redis[i] = INF;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		table[a].push_back({ b,c });
		retable[b].push_back({ a,c });
	}

	srh(X);
	resrh(X);

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, redis[i] + dis[i]);
	}
	cout << ans;
}