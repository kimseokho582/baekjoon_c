#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int check[102] = { 0, };
int table[102] = { 0, };
int result[102] = { 0, };
int rstidx = 0;
void dfs(int idx,int start) {
	if (check[idx]) {
		if (idx == start) {
			result[rstidx++] = start;
		}
	}
	else {
		check[idx] = 1;
		dfs(table[idx], start);
	}
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> table[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		dfs(i, i);
	}
	cout << rstidx << endl;
	for (int i = 0; i < rstidx; i++) {
		cout << result[i] << endl;
	}
}