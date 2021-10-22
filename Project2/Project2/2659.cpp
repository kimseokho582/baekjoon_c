#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

using namespace std;
int ans, maxi;

int getClockNum(string s) {
    deque <char> dq;
    int smallInt = 99999;
    for (int i = 0; i < s.size(); i++) {
        dq.push_back(s[i]);
    }

    for (int i = 0; i < s.size(); i++) {
        string tmp = "";
        for (int j = 0; j < s.size(); j++)
            tmp += dq.at(j);
        smallInt = min(smallInt, stoi(tmp));
        dq.push_back(dq.front());
        dq.pop_front();
    }
    return smallInt;
}

int main() {
    string num = "";
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        num += s;
    }
    for (int card = 1111; card <= 9999; card++) {
        string s = to_string(card);
        int clockNum = getClockNum(s);
        if (maxi < clockNum) {
            maxi = clockNum;
            ans++;
        }
        if (clockNum == getClockNum(num)) {
            cout << ans;
            break;
        }
    }
}