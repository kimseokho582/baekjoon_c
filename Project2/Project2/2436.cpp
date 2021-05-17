#include <iostream>
using namespace std;

long long a, b, num, ans1, ans2;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	num = b / a;
	long long tmp1 = 0, tmp2 = num;
	for (int i = 1; tmp1 < tmp2; i++) {
		if (num % i == 0) {
			tmp1 = i;
			tmp2 = num / i;
		}
		if (tmp1 > tmp2)continue;
		int check = 1;
		int cnt = 0;
		for (long long j = 1; j <= tmp1; j++) {
			if (tmp1 % j == 0 && tmp2 % j == 0) {
				cnt++;
			}
			if (cnt > 1) {
				check = 0;
				break;
			}
		}
		if (check == 1){
			ans1 = tmp1 * a;
			ans2 = tmp2 * a;
		}
		
	}
	cout << ans1 << " " << ans2;
}