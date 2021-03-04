#include <iostream>
#include <algorithm>
using namespace std;

int table[9];
int numbers[9];
int check[9];
int N, M;

void calc(int num, int idx) {

    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << table[i] << " ";
        }cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!check[i]) {
            check[i] = 1;
            table[idx] = numbers[i];
            calc(num + 1, idx + 1);
            check[i] = 0;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    sort(numbers, numbers + N);
    calc(0, 0);
}