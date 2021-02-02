#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, string>>table;
int N;

bool cmp(pair<int, string>x, pair<int, string>y) {

    return x.first < y.first;
}
int main() {
    cin >> N;
    table.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> table[i].first >> table[i].second;
    }
    stable_sort(table.begin(), table.end(), cmp);
    for (int i = 0; i < N; i++) {
        cout << table[i].first << " " << table[i].second << "\n";
    }
}
