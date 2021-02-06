#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N; cin >> N;
    deque<int>deque;
    string str;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> str;
        if (str == "push_front") {
            cin >> num;
            deque.push_front(num);
            continue;
        }
        else if (str == "push_back") {
            cin >> num;
            deque.push_back(num);
            continue;
        }
        else if (str == "pop_front") {
            if (deque.empty())
                cout << -1 << endl;
            else {
                cout << deque.front() << endl;
                deque.pop_front();
            }
            continue;
        }
        else if (str == "pop_back") {
            if (deque.empty())
                cout << -1 << endl;
            else {
                cout << deque.back() << endl;
                deque.pop_back();
            }
            continue;
        }
        else if (str == "size") {
            cout << deque.size() << endl;
            continue;
        }
        else if (str == "empty") {
            cout << (deque.empty() ? 1 : 0) << endl;
            continue;
        }
        else if (str == "front") {
            cout << (deque.empty() ? -1 : deque.front()) << endl;
            continue;
        }
        else if (str == "back") {
            cout << (deque.empty() ? -1 : deque.back()) << endl;
            continue;
        }
    }

}