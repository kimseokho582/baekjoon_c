#include <iostream>

using namespace std;

float table[3][2] = { 0, };
int times = 0;
float newruler=0;
void calc(float ruler) {
	if (table[times][0] != table[times][1]) {
		float fold = (float)(table[times][0] + table[times][1]) / 2;
		if (fold > (float)ruler / 2) {
			newruler = fold;
			for (int i = times ; i < 3; i++) {
				for (int j = 0; j < 2; j++) {
					if (table[i][j] > fold)
						table[i][j] = 2 * fold - table[i][j];
				}
			}
		}
		else {
			newruler = ruler - fold;
			for (int i = times ; i < 3; i++) {
				for (int j = 0; j < 2; j++) {
					if (table[i][j] < fold)
						table[i][j] = 2* fold - table[i][j];
					table[i][j] = table[i][j] - fold;
				}
			}
		}

	}


	times++;
	if (times == 3)
		return;
	else
		calc(newruler);
	

}

int main() {
	int ruler; cin >> ruler;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++)
			cin >> table[i][j];
	}
	calc(ruler);
	cout << fixed;
	cout.precision(1);
	cout << newruler;
}