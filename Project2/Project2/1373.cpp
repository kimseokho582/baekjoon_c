#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int sz = str.size();

	if (sz % 3 == 1) {
		cout << str[0];
	}
	else if (sz % 3 == 2) {
		cout << (str[0] - '0') * 2 + (str[1] - '0');
	}


	for (int i = sz % 3; i < sz; i += 3) {
		cout << (str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + (str[i + 2] - '0');
	}

}