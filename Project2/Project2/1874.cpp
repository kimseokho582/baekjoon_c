#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int table[100002];
int main() {
	int n; cin >> n;
	queue<int>q;
	vector<char>v;
	stack<int>rst;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		q.push(tmp);
	}


	for (int i = 1; i <= n; i++) {
		if (!(rst.empty()) && rst.top() == q.front()) {
			v.push_back('-');
			rst.pop();
			q.pop();
			i--;
			continue;
		}
		if (!(rst.empty())&&rst.top() > q.front()) {
			cout << "NO";
			exit(0);
		}
		rst.push(i);
		v.push_back('+');

	}

	while(!q.empty()){
		if (!(rst.empty()) && rst.top() > q.front()) {
			cout << "NO";
			exit(0);
		}
		v.push_back('-');
		rst.pop();
		q.pop();
	}
	for (char x : v) {
		cout << x << " ";
	}
}