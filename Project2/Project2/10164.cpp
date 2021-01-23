#include <iostream>

using namespace std;

int table[15][15];
int main() {
	std::fill(&table[0][0], &table[15][15], 1);
	int N, M, K; cin >> N >> M >> K;
	int circleX, circleY;
	if (K % M == 0) {
		circleX = K / M-1;
		circleY = M - 1;
	}
	else {
		circleX = K / M ;
		circleY = K % M - 1;
	}

	

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
				table[i][j] = table[i][j - 1] + table[i - 1][j];
		}
	}
	if (K == 0) {
		cout << table[N - 1][M - 1] << endl;
	}
	else {
		cout << table[circleX][circleY] * table[N - 1 - circleX][M - 1 - circleY]<<endl;
	}



}