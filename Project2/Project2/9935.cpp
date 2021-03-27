#include <iostream>
#include <string>
using namespace std;

string str, boom;
string ans = "";
int main() {
	
	cin >> str >> boom;
	for (int i = 0; i < str.length(); i++) {
		ans.push_back(str[i]);
		if (str[i] == boom.back()&& ans.size() >= boom.size()) {
			bool flag = 1;
			int idx = ans.size() - 1;
			for (int j = boom.size()-1; j >= 0; j--) {
				if (ans[idx] != boom[j]) {
					flag = 0;
					
					break;
				}
				idx--;		
			}
			if (flag == 1) {
				for (int i = 0; i < boom.size(); i++) {
					ans.pop_back();
				}
			}
		}
	}
	if (ans == "") {
		cout << "FRULA";
	}
	else {
	cout << ans;

	}

}