#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	while (n--) {
		deque<string>dq;
		string cmd, str,tmp=""; int m;
		cin >> cmd >> m >> str;
		bool err = 0, rvs = 0;
		for (int i = 0; i < str.length(); i++) {
			if ('0' <= str[i] && str[i] <= '9') {
				tmp += str[i];
			}
			else {
				if(tmp.length()!=0)dq.push_back(tmp);
				tmp = "";
			}
		}
		for (int i = 0; i < cmd.length(); i++) {
			if (cmd[i] == 'R')rvs = !rvs;
			else {
				if (dq.empty()) {
					cout << "error" << "\n";
					err = 1;
					break;
				}
				else {
					rvs==0? dq.pop_front(): dq.pop_back();
				}
			}
		}

		if (err == 0) {
			cout << "[";
			if (rvs == 0) {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];
					if (i != dq.size() - 1) {
						cout << ",";
					}
				}
			}
			else {
				for (int i = dq.size() - 1; i >= 0; i--) {
					cout << dq[i];
					if (i != 0) {
						cout << ",";
					}
				}
			}
			cout << "]" << "\n";
		}
	}
}

