#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>table;
vector<string>ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string tmp; cin >> tmp;
        table.push_back(tmp);
    }

    sort(table.begin(), table.end());
    for (int i = 0; i < M; i++) {
        string tmp; cin >> tmp;
        /*if (find(table.begin(), table.end(), tmp) != table.end()) {
           ans.push_back(tmp);
        }*/
        if (binary_search(table.begin(), table.end(), tmp)) {
            ans.push_back(tmp);

        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (string x : ans)
        cout << x << "\n";
}