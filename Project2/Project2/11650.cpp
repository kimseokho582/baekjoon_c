#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>x, pair<int, int>y) {
	if (x.first == y.first)
		return x.second < y.second;
	else
		return x < y;
}
int main() {
	int N; cin >> N;
	vector<pair<int, int>>table(N);
	int firstTmp, secondTmp;
	for (int i = 0; i < N; i++) {
		cin >> table[i].first >> table[i].second;
	}
	stable_sort(table.begin(), table.end(), &cmp);
	for (pair<int, int>x : table) {
		cout << x.first << " " << x.second << "\n";
	}
}