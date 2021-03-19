#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define INF 999999999
using namespace std;

vector<pair<int, int>>table[1001];
int dis[1001];
int N, M;
bool check1=true,check2=true;
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

void lnit() {
	for (int i = 1; i <= N; i++) dis[i] = INF;
}

int main() {
	cin >> N >> M ;
	int tmp1 = 0;
	int tmp2 = 0;
	int ans;
	
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		table[a].push_back({ b,c });
		table[b].push_back({ a,c });
		
	}

	int x1, x2; cin >> x1 >> x2;

	lnit();
	srh(1);
	tmp1 += dis[x1];
	tmp2 += dis[x2];
	if (tmp1 == INF) check1 = false;
	if (tmp2 == INF)check2 = false;

	lnit();
	srh(x1);
	if (check1 == true) tmp1 += dis[x2];
	if (check2 == true) tmp2 += dis[x2];
	
	lnit();
	srh(x2); 
	if (check1 == true) tmp1 += dis[N];

	lnit();
	srh(x1);
	if (check2 == true) tmp2 += dis[N];

	if (check1 == false && check2 == false) {
		ans = -1;
	}
	else {
		ans = min(tmp1, tmp2);
	}

	if (ans == INF) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}