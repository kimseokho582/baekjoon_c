#include <iostream>
using namespace std;

const int A[15] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
const int B[15] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };


int match[6][3];
int table[6][3];
int ans[4];

void calc(int n, int time) {

	if (time == 15) {
		if (ans[n]) {
			return;
		}

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (match[i][j] != table[i][j])
					return;
			}
		}

		ans[n] = 1;
		return;

	}
	int a = A[time];
	int	b = B[time];

	match[a][0]++; match[b][2]++;
	calc(n, time + 1);
	match[a][0]--; match[b][2]--;

	match[a][2]++; match[b][0]++;
	calc(n, time + 1);
	match[a][2]--; match[b][0]--;

	match[a][1]++; match[b][1]++;
	calc(n, time + 1);
	match[a][1]--; match[b][1]--;

	

}
int main() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> table[j][k];
			}
		}
		calc(i, 0);
	}
	for (int x : ans)
		cout << x << " ";

	
}