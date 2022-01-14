#include <iostream>
#include <string>

using namespace std;

int main() {
	string s, tmp;
	int ans = 0, check = 0;
	cin >> s;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
			if (check==1) {
				ans -= stoi(tmp);
			}
			else {
				ans += stoi(tmp);
			}
			tmp = "";
			if (s[i] == '-') {
				check = 1;
			}
		}
		else {
			tmp += s[i];
		}
	}
	cout << ans;
}