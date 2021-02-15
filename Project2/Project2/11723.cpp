#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int>table;
vector<int>::iterator it;

void add(int num) {
    table.push_back(num);
    table.erase(unique(table.begin(), table.end()), table.end());
}

void remove(int num) {
    it = lower_bound(table.begin(), table.end(), num);

    if (it != table.end()) {
        table.erase(it);
    }
}
void toggle(int num) {

    if (binary_search(table.begin(), table.end(), num)) {
        remove(num);
    }
    else
    {
        add(num);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        string str; int num; cin >> str;


        if (str == "add") {
            cin >> num;
            add(num);
        }
        else if (str == "remove") {
            cin >> num;
            remove(num);
        }
        else if (str == "check") {
            cin >> num;
            if (binary_search(table.begin(), table.end(), num)) {
                cout << 1 << "\n";
            }
            else cout << 0 << "\n";

        }
        else if (str == "toggle")
        {
            cin >> num;
            toggle(num);
        }
        else if (str == "all") {
            for (int i = 1; i <= 20; i++) {
                toggle(i);
            }

        }
        else if (str == "empty") {
            table.clear();
        }
    }
}