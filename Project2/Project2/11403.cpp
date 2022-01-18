#include <iostream>
#include <algorithm>
#define INF 999999999
using namespace std;

int table[100][100];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
			if (table[i][j] == 0)table[i][j] = INF; 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				table[j][k] = min(table[j][k], table[j][i] + table[i][k]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[i][j] == INF)cout << 0 << " ";
			else cout << 1 << " ";
		}cout << endl;
	}
}