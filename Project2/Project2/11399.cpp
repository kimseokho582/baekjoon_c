#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int>table;
    int n; cin >> n; int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        table.push_back(tmp);
    }
    sort(table.begin(), table.end());


    for (int i = 0; i < n; i++) {
        ans += table[i] * (n - i);
    }
    cout << ans;
}