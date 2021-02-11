#include <iostream>

using namespace std;

int table[102][102] = { 0, };
int check[101] = { 0, };
int N, L, cnt = 0;
void search(int x) {
	check[x] = 1;
	cnt++;
	for (int i = 1; i <= N; i++) {
		if (table[x][i] == 1 && check[i] == 0) {
			search(i);
		}
	}

}
int main() {
	cin >> N >> L;
	int count = 0;
	for (int i = 0; i < L; i++) {
		int x, y; cin >> x >> y;
		table[x][y] = 1;
		table[y][x] = 1;
	}
	search(1);

	cout << cnt - 1;
}