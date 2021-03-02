#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int>table[100001];
queue<int>ssearch;
int check[100001];
int ans[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	
	for (int i = 0; i <  N - 1; i++) {
		int x, y; cin >> x >> y;
		table[x].push_back(y);
		table[y].push_back(x);
	}
	ssearch.push(1);
	while (!ssearch.empty()) {
		int parent = ssearch.front();
		check[parent] = 1;
		ssearch.pop();
		for (int i = 0; i < table[parent].size(); i++) {
			if (check[table[parent][i]]!= 1) {
				ssearch.push(table[parent][i]);
				ans[table[parent][i]] = parent;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << ans[i] << "\n";
	}
}