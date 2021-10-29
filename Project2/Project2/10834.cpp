#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	long long answer = 1;
	int x = 0;
	for (int i = 0; i < n; i++) {
		long long a, b, c; cin >> a >> b >> c;
		answer = (answer * b) / a;
		if (c == 1)x = !x;
	}
	cout << x<<" "<<answer;
}

