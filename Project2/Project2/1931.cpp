#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*bool cmp(pair<int, int>x, pair<int, int>y) {
   return x.second < y.second;
}*/

vector<pair<int, int>>table;

int main() {

    int N;   scanf("%d", &N);
    int in, out;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &in, &out);
        table.push_back(make_pair(out, in));

    }

    sort(table.begin(), table.end());

    int quickTime = 0; int ans = 0;

    for (int i = 0; i < table.size(); i++) {
        int start = table[i].second, end = table[i].first;
        if (quickTime <= start)
        {
            quickTime = end;
            ans++;
        }
    }
    printf("%d", ans);
}