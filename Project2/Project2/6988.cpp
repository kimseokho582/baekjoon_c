#include <iostream>
using namespace std;


int table[3000];
int N;
int largeTerm;

int seq(int i,int j,int term) {
	for (int k = 0; k < N; k++) {
		if (table[i + j] + term == table[i + j + k]) {
			return table[i] + table[i + j] + table[i + j + k];
		}
	}
	return 0;
}
int incre(int term) {
	int sum;
	int max = 0;
	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i + j] == table[i] + term) {
				sum = seq(i, j, term);
				if (max < sum)
					max = sum;
				break;
			}
		}
	}
	return max;
}

int main() {
	scanf_s("%d", &N);
	int ans = 0;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &table[i]);
	}
	largeTerm = table[N - 1] / 2;
	for (int i = 1; i <= largeTerm; i++) {
		tmp = incre(i);
		if (ans < tmp)
			ans = tmp;
	}
	cout << ans;
}