#include <iostream>
using namespace std;

int main() {
	int num; cin >> num;
	int i;
	for (i = 0; num > 0; i++) {
		num -= i;
	}
	if ((i - 1) % 2 == 0) {
		cout << i + num - 1 << "/" << 1 - num;
	}
	else
		cout << 1 - num << "/" << i + num - 1;
}
