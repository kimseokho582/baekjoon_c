#include <iostream>
using namespace std;
int cnt[4], n;


int  main() {
	
	for (int i = 0; i < 3; i++)cin >> cnt[i];
	cin >> n;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < n / cnt[0] + 1; i++) {
		a = cnt[0] * i;
		for (int j = 0; j < n / cnt[1] + 1; j++) {
			b = cnt[1] * j;
			for (int k = 0; k < n / cnt[0] + 1; k++) {
				c = cnt[2] * k;
				if (a + b + c == n) {
					cout << 1;
					return 0;
				}

			}
		}
	}
	cout << 0;

}