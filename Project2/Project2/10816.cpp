#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {


    int N; cin >> N;
    vector<int> table(N);

    for (int i = 0; i < N; i++)
        scanf_s("%d", &table[i]);

    sort(table.begin(), table.end());
    int M;  cin >> M;

    vector<int> ans(M);
    int tmp = 0;
    for (int i = 0; i < M; i++) {
        scanf_s("%d", &tmp);
        auto up = upper_bound(table.begin(), table.end(), tmp);
        auto low = lower_bound(table.begin(), table.end(), tmp);

        ans[i] = up - low;
    }

    for (int x : ans)
        cout << x << " ";

    return 0;
}