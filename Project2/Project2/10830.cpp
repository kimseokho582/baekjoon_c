#include <iostream>
using namespace std;

long long ans[5][5];
long long x[5][5];
long long tmp[5][5];
long long N, T;

void calc(long long xx[5][5], long long yy[5][5]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < N; k++) {
				tmp[i][j] += xx[i][k] * yy[k][j];
			}
			tmp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			xx[i][j] = tmp[i][j];
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	 cin >> N >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >>x[i][j];
		}ans[i][i] = 1;
	}
	while (T > 0)
	{
		if (T % 2==1) {
			calc(ans, x);
		
		}
		calc(x, x);
		T /= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << " ";
		}cout << "\n";
	}
}