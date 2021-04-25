#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>>table[1001];
int path[1001];
int dij[1001];
vector<int>vpath;

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
				path[nCur] = cur;
				dij[nCur] = nVal;
				pq.push({ -nVal,nCur });
				
			}
		}
	}
}
void init() {
	for (int i = 0; i < 1001; i++) {
		dij[i] = 999999999;
	}
}
int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		table[a].push_back({ b,c });
	}
	int src, dst; cin >> src >> dst;
	init();
	srh(src);
	int tmp = dst;
	while (tmp != src) {
		vpath.push_back(tmp);
		tmp = path[tmp];
	}
	vpath.push_back(src);
	reverse(vpath.begin(),vpath.end());


	cout << dij[dst]<<endl<<vpath.size()<<endl;
	for (int x : vpath) cout << x << " ";
}