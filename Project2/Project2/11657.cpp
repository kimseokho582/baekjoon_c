#include <iostream>
#include <vector>
#define INF 999999999
using namespace std;
long long bell[501] = { 0, };
vector<pair<pair<int, int>, int>>table;
int n, m;
bool check;

void srh() {
	check = false;
	bell[1] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < table.size(); j++) {
			int src = table[j].first.first;
			int dst = table[j].first.second;
			int val = table[j].second;

			if (bell[src] == INF) continue;
			if (bell[dst] > bell[src] + val) bell[dst] = bell[src] + val;
		}
	}

	for (int j = 0; j < table.size(); j++) {
		int src = table[j].first.first;
		int dst = table[j].first.second;
		int val = table[j].second;

		if (bell[src] == INF) continue;
		if (bell[dst] > bell[src] + val) {
			check = true;
			return;
		}

	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		bell[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		table.push_back({ {a,b},c });
	}
	srh();
	if (check) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= n; i++) {
			bell[i] == INF ? cout << -1 << endl : cout << bell[i];
			if (i != n)cout << endl;
		}
	}

}