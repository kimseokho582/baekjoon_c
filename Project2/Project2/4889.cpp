#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	int num = 1;
	while (1) {
		int ans = 0;
		cin >> str;
		if (str[0] == '-')break;
		
		stack<char>st;
		for (int i = 0; i < str.size(); i++) !st.empty()&&str[i] == '}' && st.top() == '{'  ? st.pop() : st.push(str[i]);

		while (!st.empty()) {
			char tmp1 = st.top();
			st.pop();
			char tmp2 = st.top();
			st.pop();
			if (tmp1 == tmp2)ans++;
			else ans += 2;
		}
		cout << num++ << ". " << ans << '\n';
	}
	return 0;
}
