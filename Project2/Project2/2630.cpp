#include<iostream>

using namespace std;

int table[128][128];
int color = 0, blue = 0, white = 0;

void calc(int x,int y,int n) {
	color = table[x][y];
	int check = 0;
	for (int i = x; i < n+x; i++) {
		for (int j = y; j < n + y; j++) {
			if (table[i][j]!=color) {
				calc(x, y, n / 2);
				calc(x + n / 2, y, n / 2);
				calc(x, y + n / 2, n / 2);
				calc(x + n / 2, y + n / 2, n / 2);
				return;
			}
			
		}
	}
	if (check == 0) {
		color == 1 ? blue++ : white++;
	}

	
}

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
		}
	}

	calc(0, 0, N);
	cout  << white << endl <<blue;

}
