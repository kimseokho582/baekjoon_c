#include <iostream>
using namespace std;

int gcd(int x, int y) {
	int tmp;
	while (y != 0) {
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while (n--) {
		int M, N, x, y; cin >> M >> N >> x >> y;
		int i = 0, j = 0;
		int max = M * N / gcd(M, N);
		int tmpM =x, tmpN =y;
		int flag = 0;
		while (tmpM <= max && tmpN <= max) {
			
			if (tmpM == tmpN) {
				cout << tmpM << endl;
				flag = 1;
				break;
			}
			else {
				if (tmpM > tmpN) {
					j++;
				}
				else {
					i++;
				}
			}
			tmpM = M * i + x, tmpN = N * j + y;
		}
		if (flag == 0)cout << -1 << endl;
		
	}
}