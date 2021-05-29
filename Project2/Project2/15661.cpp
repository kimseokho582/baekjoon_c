#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int table[20][20];
int n, result = 999999999;


void calc(int x) {
	vector<int> tmp;
	for (int i = 0; i < n; i++) {
		i < x ? tmp.push_back(0) : tmp.push_back(1);
	}
	do {
		vector<int> select, Nselect;
		int ss = 0, Nss = 0;
		for (int i = 0; i < n; i++) {
			tmp[i]? Nselect.push_back(i): select.push_back(i);
		}

		for (int i = 0; i < select.size() - 1; i++) {
			for (int j = i + 1; j < select.size(); j++) {
				ss += (table[select[i]][select[j]] + table[select[j]][select[i]]);
			}
		}
		for (int i = 0; i < Nselect.size() - 1; i++) {
			for (int j = i + 1; j < Nselect.size(); j++) {
				Nss += (table[Nselect[i]][Nselect[j]] + table[Nselect[j]][Nselect[i]]);
			}
		}

		result = min(result, abs(ss - Nss));
	} while (next_permutation(tmp.begin(), tmp.end()));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
		}
	}

	for (int i = 1; i < n/2+1; i++) {
		calc(i);
	}
	cout << result;
}