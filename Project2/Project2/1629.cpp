#include <iostream>

using namespace std;

long long search(long long a, long long b, long long c) {
	if (b == 0) return 1;
	long long ans = search(a, b / 2, c);
	ans = ans * ans % c;

	if (b % 2 == 0) return ans;
	else return (ans * a) % c;
}

int main() {
	long long A, B, C; cin >> A >> B >> C;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << search(A, B, C);
}