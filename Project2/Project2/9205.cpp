#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int sx, sy; cin >> sx >> sy;
		vector<pair<int, pair<int, int>>>v;
		int visited[200] = { 0, };
		int flag = 0;
		for (int i = 0; i < n + 1; i++) {
			int tmpx, tmpy; cin >> tmpx >> tmpy;
			i == n ? v.push_back({ 1,{tmpx,tmpy} }) : v.push_back({ 0,{tmpx,tmpy} });
		}

		queue < pair<int, pair<int, int>>>q;
		q.push({ 0,{0,0} });
		while (!q.empty()) {
			int x = q.front().second.first;
			int y = q.front().second.second;
			int home = q.front().first;
			q.pop();
			if (home == 1) {
				cout << "happy"<<endl;
				flag = 1;
				break;
			}
			for (int i = 0; i < v.size(); i++) {
				if (visited[i] == 1) continue;

				int nx = v[i].second.first;
				int ny = v[i].second.second;
				int nhome = v[i].first;
				if (abs(x - nx) + abs(y - ny) <= 1000) {
					q.push({ nhome,{nx,ny} });
					visited[i] = 1;
					
				}
			}
		}
		if(flag==0)cout << "sad" << endl;

	}
}
