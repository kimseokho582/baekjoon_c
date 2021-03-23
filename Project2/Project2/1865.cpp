#include <iostream>
#include <vector>
#include <cstring>
#define INF 999999999
using namespace std;

bool check;
vector<pair<pair<int, int>, int>>table;
int bell[502];
int N, M, W;



void srh() {
	check = false;
	bell[1] = 0;
	for (int i = 1; i <= N - 1; i++) {
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
	return;
}

void init() {

	cin >> N >> M >> W;
	for (int i = 1; i <= 500; i++) {
		bell[i] = INF;
	}
	memset(bell, -1, sizeof(bell));
	//무조건 1로 시작해서 1과 단절된경우(INF) 찾아갈수 없어서 INF가 아닌 아무값(-1)로 초기화함
	for (int i = 0; i < M; i++) {
		int S, E, T; cin >> S >> E >> T;
		table.push_back({ {S,E},T });
		table.push_back({ {E,S},T });
	}
	for (int i = 0; i < W; i++) {
		int S, E, T; cin >> S >> E >> T;
		table.push_back({ {S,E},-T });
	}
	srh();
	if (check == true) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	table.clear();
}

int main() {
	int TC; cin >> TC;
	while (TC-- > 0) {
		init();
	}
}