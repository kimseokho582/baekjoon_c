#include <iostream>
#include <queue>

using namespace std;

int check[10001] = { 0, };
int n, a, b;

string calc(int x) {
	queue<pair<int, string>>q;
	q.push({ x, "" });
	check[x] = 1;

	while (!q.empty()) {
		int xx = q.front().first;
		string ss = q.front().second;
		q.pop();

		if (xx == b) {
			return ss;
		}

		int nx = (xx * 2) % 10000;
		if (!check[nx]) {
			q.push({ nx,ss + "D" });
			check[nx] = 1;
		}

		xx == 0 ? nx = 9999 : nx = xx - 1;
		if (!check[nx]) {
			q.push({ nx,ss + "S" });
			check[nx] = 1;
		}

		nx = (xx % 1000) * 10 + (xx / 1000);
		if (!check[nx]) {
			q.push({ nx,ss + "L" });
			check[nx] = 1;
		}

		nx = (xx / 10) + (xx % 10) * 1000;
		if (!check[nx]) {
			q.push({ nx,ss + "R" });
			check[nx] = 1;
		}

	}
}

void init(int x[]) {
	for (int i = 0; i < 10001; i++) {
		x[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		init(check);
		cin >> a >> b;
		cout << calc(a) << endl;
	}
}
