#include <iostream>
using namespace std;
int table[10002];


void srh(int x, int y) {
	if (x > y) return;
	int root = table[x];
	int point = y;
	while (root < table[point]) {
		point--;
	}

	srh(x + 1, point);
	srh(point + 1, y);
	cout << root << endl;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num;
	int i = 0;
	while (cin >> num) {
		if (num == EOF) break;
		table[i++] = num;
	}
	srh(0, i - 1);
}