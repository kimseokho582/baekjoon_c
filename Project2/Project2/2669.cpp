#include <iostream>
using namespace std;

#define MAX_SIZE 102

int table[MAX_SIZE][MAX_SIZE] = { 0, };

int bottomX, topX, bottomY, topY;
int areaSize = 0;

void sizeCalculate(int x1,int y1,int x2,int y2) {
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			if (!table[i][j]) {
				table[i][j] = 1;
				areaSize++;
			}
		}
	}
}


int main() {

	for (int i = 0; i < 4; i++) {
		cin >> bottomX>>bottomY >> topX >>topY;
		sizeCalculate(bottomX, bottomY, topX, topY);
	}
	cout << areaSize;

}