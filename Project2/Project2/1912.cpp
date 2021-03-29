#include <iostream>
using namespace std;
int N, num, ans;
int large(int x, int y) {
	if (x > y) return x; 
	else return y;
}

int main() {
	cin >> N >> num;
	ans = num;
	for (int i = 1; i < N; i++) {
		int in; cin >> in;
		num = large(in, in + num);
		ans = large(num, ans);
	}
	cout << ans;
}