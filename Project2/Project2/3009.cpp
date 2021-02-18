#include <iostream>
using namespace std;

int main() {
	int x[4] = { 0, };
	int y[4] = { 0, };
	int xx, yy;

	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	if (x[0] != x[1])
		if (x[0] == x[2])
			xx = x[1];
		else
			xx = x[0];
	else
		xx = x[2];

	if (y[0] != y[1])
		if (y[0] == y[2])
			yy = y[1];
		else
			yy = y[0];
	else
		yy = y[2];

	cout << xx << " " << yy;
}