#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n; cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i].second << " " << v[i].first << "\n";
	}
}