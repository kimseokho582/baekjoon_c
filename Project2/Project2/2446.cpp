#include <iostream>
using namespace std;

int main() {
	int a; cin >> a;
	int k = 1;
	for (int i = 1; i > 0; i += k) {
		for (int j = 1; j <= a; j++) {
			if (i <= j)cout << "*";
			else cout << " ";
		}
		for (int j = 1; j < a; j++) {
			if (i <= a - j)cout << "*";
		}
		cout << '\n';
		if (i > a - 1)k *= -1;
	}
}