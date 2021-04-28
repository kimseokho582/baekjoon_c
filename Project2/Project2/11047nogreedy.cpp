#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>table;
int n, val;



int main() {
	cin >> n >> val;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp > val)continue;
		table.push_back(tmp);
	}
	int ans = 100000001;
	for (int j = table.size() - 1; j >= 0; j--) {
		int cal = val; int tmp = 0;
		for (int i = j; i >= 0; i--) {
			while (1) {

				cal -= table[i];
				tmp++;


				if (cal < 0) {
					cal += table[i];
					tmp--;
					break;
				}

			}

		}ans = min(ans, tmp);
	}
	cout << ans;
}
