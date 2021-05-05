#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int>table[2001];
int check[2001];
int n, m;
bool ans = false;

void calc(int x,int cnt) {
	check[x] = 1;
	if (cnt == 4) {
		ans = true;
		return;
	}
	for (int i = 0; i < table[x].size(); i++) {
		if (check[table[x][i]] == 0) {
			calc(table[x][i], cnt + 1);
			if (ans == true)return;
		}
	}
	check[x] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		table[a].push_back(b);
		table[b].push_back(a);
	}

	for (int i = 0; i < m; i++) {
		memset(check, 0, sizeof(check));
		
		calc(i, 0);
		
		if (ans == true) break;
		
	}
	if (ans == true)cout << 1;
	else cout << 0;
}