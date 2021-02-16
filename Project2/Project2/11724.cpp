#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, cnt = 0, table[1001][1001] = { 0, }, check[1001] = { 0, };

void search(int x) {

    check[x] = 1;
    for (int i = 1; i <= N; i++) {
        if (table[x][i] && !check[i]) {
            search(i);
        }

    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        table[x][y] = table[y][x] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if (!check[i]) {
            cnt++;
            search(i);
        }
    }
    cout << cnt;
}