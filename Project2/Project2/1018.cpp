#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string startW[8] = { 
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
};
string startB[8] = {
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
};

string table[50];
int N, M;
int startWCount = 0;
int startBCount = 0;
int small = 9999;

int White(int x, int y) {

	int cnt = 0;
	for (int i = 0 + x; i < 8 + x; i++) {
		for (int j = 0 + y; j < 8 + y; j++) {
			if (table[i][j] != startW[i - x][j - y])
				cnt++;
		}
	}
	return cnt;
}

int Black(int x, int y) {

	int cnt = 0;
	for (int i = 0 + x; i < 8 + x; i++) {
		for (int j = 0 + y; j < 8 + y; j++) {
			if (table[i][j] != startB[i - x][j - y])
				cnt++;
		}
	}
	return cnt;
}


int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> table[i];
	}

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			small = min(small, min(White(i, j), Black(i, j)));
		}
	}
	

	cout << small;
}