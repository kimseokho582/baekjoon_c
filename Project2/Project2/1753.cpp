#include <iostream>
#include <queue>
#include<vector>
#define MAX 999999999

using namespace std;
vector<pair<int, int>>table[20001];
int  V, E, K;
int check[20001];
void calc() {
	priority_queue<pair<int, int>>search;
	search.push(make_pair(0, K));
	check[K] = 0;
	while (!search.empty()) {
		int val = -search.top().first;
		int src = search.top().second;
		search.pop();
		for (int i = 0; i < table[src].size(); i++) {
			if (check[table[src][i].first] > val + table[src][i].second) {
				check[table[src][i].first] = val + table[src][i].second;
				search.push(make_pair(-check[table[src][i].first], table[src][i].first));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (check[i] == MAX) {
			cout << "INF" << "\n";
		}
		else
		{
			cout << check[i] << "\n";
		}
	}
}


int  main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		table[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= V; i++) {
		check[i] = MAX;

	}
	calc();


}