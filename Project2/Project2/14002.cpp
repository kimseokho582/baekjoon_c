#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n; int ans = 0;
	vector<pair<int, int>>table(n);
	vector<int>ansarr(n+1);
	cin >> table[0].first; table[0].second = 1;
	ansarr[table[0].second] = table[0].first;
	for (int i = 1; i < n; i++) {
		cin >> table[i].first; table[i].second = 1;
		for (int j = 0; j < i; j++) {
			if (table[i].first > table[j].first&& table[i].second < table[j].second + 1) {
				table[i].second = table[j].second + 1;
				
				
			}

		}

	}

	for (int i = 0; i < n; i++) ans = max(ans, table[i].second);
	cout << ans<<endl;
	for (int i = 1; i <= ans; i++) {
		cout << ansarr[i] << " ";
	}

}