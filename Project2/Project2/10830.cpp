#include <iostream>
using namespace std;

int ans[5][5];
int x[5][5];

int N, T;

void calc(int xx[5][5],int yy[5][5]) {
	int tmp[5][5];
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
			ans[i][j] = tmp[i][j];
		}
	}
}


int main() {
	 cin >> N >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ans[i][j];
			x[i][j] = ans[i][j];
		}
	}
	while (T > 1) {
		calc(ans,x);
		T--;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << " ";
		}cout << endl;
	}
}