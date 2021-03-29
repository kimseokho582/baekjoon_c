#include <iostream>
#include <algorithm>

using namespace std;
int table[1001];
int inc[1001];
int reinc[1001];

int large = 0;
int main() {
	int N; cin >> N;
	int large = 0; int largeIdx;
	for (int i = 1; i <= N; i++) {
		cin >> table[i];
	}
	

	for (int i = 1; i <= N; i++) {
		inc[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (table[i] > table[j] && inc[j] + 1 > inc[i]) {
				inc[i] = inc[j]+1;
			}
		}
	}
	for (int i = N ; i >= 1; i--) {
		reinc[i] = 1;
		for (int j = N; j >= i; j--) {
			if (table[i] > table[j] && reinc[j]+1 > reinc[i]) {
				reinc[i] = reinc[j] + 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		large = max(large, inc[i] + reinc[i]);
	}
	cout << large-1;
}