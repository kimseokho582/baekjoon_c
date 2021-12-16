#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n; cin >> n;
	int answer = 0;
	stack<int>s;
	while (n--) {
		int tmp; cin >> tmp;
		if (tmp != 0) {
			s.push(tmp);
			answer += tmp;
		}
		else {
			answer -= s.top();
			s.pop();

		}
	}
	cout << answer;
}