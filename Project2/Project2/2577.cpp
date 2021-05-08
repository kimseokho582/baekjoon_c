#include <iostream>
using namespace std;

int main() {
	int n[10] = { 0 };
	int a, b, c; cin >> a >> b >> c;
	int t;
	t = a * b * c;
	while (t != 0) {
		n[t % 10]++;
		t /= 10;
	}
	for (int i = 0; i < 10; i++)cout << n[i] << endl;

}