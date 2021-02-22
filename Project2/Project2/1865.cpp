#include <iostream>
#include <queue>
#define LOAD_MAX 2501
#define WORM_MAX 201	
using namespace std;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int TC; cin >> TC;
	while (TC--) {
		int yncheck = 0;
		int N, M, W; cin >> N >> M >> W;
		vector<pair<int, int>>load[LOAD_MAX];
		vector<pair<int, int>>worm[WORM_MAX];
		int start[WORM_MAX] = { 0, }, end[WORM_MAX] = { 0, };
		int check[LOAD_MAX] = { 0, };
		for (int i = 1; i <= N; i++) {
			check[i] = 25000001;
		}
		int S, E, T;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			load[S].push_back(make_pair(E, T));
			load[E].push_back(make_pair(S, T));
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			worm[S].push_back(make_pair(E, T));
			start[i] = S, end[i] = E;
		}


		for (int k = 0; k < W; k++) {
			queue<pair<int, int>>search;
			int src = end[k], dst = start[k];
			search.push(make_pair(0, src));
			int val = 0; int go = src;

			while (go != dst) {
				val = -search.front().first;
				go = search.front().second;
				search.pop();
				for (int i = 0; i < load[go].size(); i++) {
					if (check[load[go][i].first] > load[go][i].second + val) {
						check[load[go][i].first] = load[go][i].second + val;

						search.push(make_pair(-check[load[go][i].first], load[go][i].first));
					}
				}
			}
			for (int i = 0; i < worm[start[k]].size(); i++) {
				if (check[dst] < worm[start[k]][i].second) {
					yncheck = 1;
					break;
				}
			}

		}
		if (yncheck == 1) {
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

}