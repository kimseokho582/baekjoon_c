#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N; cin >> N;
	stack<int>stack;
	string str;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			stack.push(num);
			continue;
		}
		else if (str == "pop") {
			if (stack.empty())
				cout << -1<<endl;
			else {
				cout << stack.top()<<endl;
				stack.pop();
			}
			continue;
		}
		else if (str == "size") {
			cout << stack.size()<<endl;
			continue;
		}
		else if (str == "empty") {
			cout << (stack.empty() ? 1 : 0)<<endl;
			continue;
		}
		else if (str == "top") {
			cout <<( stack.empty() ? -1 : stack.top())<<endl;
			continue;
		}
	}

}