#include <iostream>

using namespace std;

int ssize[1001] = { 0, };
int table[101][101] = { 0, };
int coordi[1001][4];

int main() {
	int N; cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> coordi[i][j];
		}
	}
	


	for (int i = 1; i <= N; i++) {
		for (int j = coordi[i][0]; j < coordi[i][0]+coordi[i][2]; j++) {
			for (int k = coordi[i][1]; k < coordi[i][1]+coordi[i][3]; k++) {
				table[j][k] = i;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 101; k++) {
				if (i == table[j][k]) {
					ssize[i]++;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << ssize[i] << endl;
}