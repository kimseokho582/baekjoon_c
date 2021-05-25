#include <iostream>
using namespace std;

int table[1500];
int  main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M; cin >> N >> M;
	for (int i = 0; i < 2*N - 1; i++) {
		table[i] = 1;
	}
	for (int i = 0; i < M; i++) {
		int z, o, t; cin >> z >> o >> t;
		int a = z;
		while (o--) {
			table[a]++;
			a++;
		}
		while (t--) {
			table[a] += 2;
			a++;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == 0) {
				cout << table[N - 1 - i] << " ";
			}
			else {
				cout << table[N - 1 + j] << " ";
			}
		}cout << endl;
	}

}