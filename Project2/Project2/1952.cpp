#include <iostream>

using namespace std;

int main() {
	int x, y; cin >> x >> y;
	if (x > y) {
		cout << (y - 1) * 2 + 1;
	}
	else {
		cout << (x - 1) * 2;
	}
}