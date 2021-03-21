#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;
vector<pair<int, int>>table[1001];
int dij[1002];
void srh(int x) {

	priority_queue<pair<int, int>>pq;
	pq.push({ 0,x });
	while (!pq.empty()) {
		int val = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dij[cur] < val) {
			continue;
		}

		for (int i = 0; i < table[cur].size(); i++) {
			int nVal = val + table[cur][i].second;
			int nCur = table[cur][i].first;

			if (nVal < dij[nCur]) {
				dij[nCur] = nVal;
				pq.push({ -nVal,nCur });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N,M; cin >> N>>M;

	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		table[a].push_back({ b,c });
	}
	int src, dst; cin >> src >> dst;

	for (int i = 1; i <= N; i++)dij[i] = INF;
	srh(src);
	cout << dij[dst];
}