#include <iostream>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    int ans = 1;
    for (int i = 0; i < M; i++) {
        ans = ans * (N - i) / (i + 1);
    }
    cout << ans;
}