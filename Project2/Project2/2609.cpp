#include <iostream>

using namespace std;


 
int main() {
	int x, y; cin >> x >> y;
	int ans;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0&&y%i==0) {
			ans = i;
		}
	}
	
	cout << ans << endl << (x / ans) * (y / ans) * ans;


}