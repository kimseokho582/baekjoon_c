#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>table;
int ans[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        table.push_back(make_pair(num, i));

    }
    sort(table.begin(), table.end());
    int cmp = table[0].first, cnt = 0; ans[table[0].second] = 0;
    for (int i = 1; i < n; i++) {
        if (cmp != table[i].first) {
            ans[table[i].second] = ++cnt;
            cmp = table[i].first;
        }
        else {
            ans[table[i].second] = cnt;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}