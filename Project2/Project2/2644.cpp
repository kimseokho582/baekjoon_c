#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>>v(101);
queue<pair<int,int>>q;
int check[101] = { 0, };
int main() {
	int n,x,y,m; cin >> n>>x>>y>>m;
	while(m--) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	q.push({ 0,x });
	check[x] = 1;

	while (!q.empty()) {
		int cnt = q.front().first;
		int point = q.front().second;
		cout << cnt <<" "<<point<< endl;

		q.pop();
		if (point == y) {
			cout << cnt<<endl;
			return 0;
		}
		
		for (int i = 0; i < v[point].size(); i++) {
			int ncnt = cnt+1;
			int npoint = v[point][i];
			if (check[npoint] != 1) {
				q.push({ ncnt,npoint });
				check[npoint] = 1;
			}
		}
	}
	cout << -1;

}