#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N; cin >> N;
    queue<int>queue;
    string str;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> str;
        if (str == "push") {
            cin >> num;
            queue.push(num);
            continue;
        }
        else if (str == "pop") {
            if (queue.empty())
                cout << -1 << endl;
            else {
                cout << queue.front() << endl;
                queue.pop();
            }
            continue;
        }
        else if (str == "size") {
            cout << queue.size() << endl;
            continue;
        }
        else if (str == "empty") {
            cout << (queue.empty() ? 1 : 0) << endl;
            continue;
        }
        else if (str == "front") {
            cout << (queue.empty() ? -1 : queue.front()) << endl;
            continue;
        }
        else if (str == "back") {
            cout << (queue.empty() ? -1 : queue.back()) << endl;
            continue;
        }
    }

}