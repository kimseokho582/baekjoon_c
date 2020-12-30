#include <iostream>

using namespace std;

int table[20][20] = { 0, };

int x, y;

int east(int i, int j, int n, int count) {
	if (count == 5) {
		return 1;
	}

	if (n == table[i][j + 1]) {
		count++;
		if (i  < 19 && j+1 < 19)
			east(i, j + 1, n, count);
	}
	else
		return 0;
}

int southeast(int i, int j, int n, int count) {
	if (count == 5) {
		return 1;
	}

	if (n == table[i + 1][j + 1]) {
		count++;
		if (i + 1 < 19 && j+1 < 19)
			southeast(i + 1, j + 1,n, count);
	}
	else
		return 0;
}

int south(int i, int j, int n, int count) {

	if (count == 5) {
		return 1;
	}

	if (n == table[i + 1][j]) {
		count++;
		if (i + 1 < 19 && j < 19)
			south(i + 1, j,n, count);
	}
	else
		return 0;
}

int southwest(int i, int j, int n, int count) {

	if (count == 5) {
		return 1;
	}

	if (n == table[i + 1][j - 1]) {
		count++;
		if (i + 1 < 19 && j >0)
			southwest(i + 1, j - 1,n, count);
	}
	else
		return 0;
}

int calc(int i, int j, int n) {

	x = i; y = j;

	if (east(i, j, n, 1) == 1)
		return 1;
	if (southeast(i, j, n, 1) == 1)
		return 1;
	if (south(i, j, n, 1) == 1)
		return 1;
	if (southwest(i, j, n, 1) == 1)
		return 1;

}

int main() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> table[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (table[i][j] != 0) {
				result = calc(i, j, table[i][j]);
				if (result == 1) {
					cout << table[i][j] << endl;
					cout << i+1 << " " << j+1;
					return 0;
				}
			}
		}
	}
}