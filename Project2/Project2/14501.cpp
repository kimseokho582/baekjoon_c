#include <iostream>
#include <algorithm>
using namespace std; 

int n;
int val[16], day[16], ans = 0;

void calc(int d, int v) {
	if (d == n + 1) {
		ans = max(ans, v);
		return;

	}
	if (d + day[d] <= n + 1) {
		calc(d + day[d], v + val[d]);
	}
	if (d + 1 <= n + 1) {
		calc(d + 1,v);
	}


}
int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> day[i] >> val[i];
	}
	calc(1, 0);
	cout << ans;
}