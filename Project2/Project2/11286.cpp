#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct cmp {
	bool operator()(const int& x, const int& y) {
		if (abs(x) != abs(y)) {
			return abs(x) > abs(y);
		}
		else {
			return x > y;
		}
	}
};

int main() {
	priority_queue<int,vector<int>,cmp >q;

	int n; cin >> n;
	while (n--) {
		int m; cin >> m;
		if (m != 0) {
			q.push(m);
		}
		else {
			if (!q.empty()) {
				cout << q.top()<<endl;
				q.pop();
			}
			else {
				cout << 0 << endl;
			}
		}
	}

}