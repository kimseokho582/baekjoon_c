#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>>table;

int main() {

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; //cin >> tmp;
        scanf_s("%d", &tmp);
        if (tmp != 0) {
            table.push(tmp);
        }
        else {
            if (!table.empty()) {
                //cout<<table.top() << endl;
                printf("%d\n", table.top());
                table.pop();
            }
            else {
                //cout<<0 << endl;
                printf("%d\n", 0);
            }
        }
    }
}