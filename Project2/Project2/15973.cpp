#include <iostream>

using namespace std; 

int main() {
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;

	int i = x1 > a1 ? x1 : a1;
	int j = x2 < a2 ? x2 : a2;
	int ji = j - i;
	int p = y1 > b1 ? y1 : b1;
	int q = y2 < b2 ? y2 : b2;
	int qp = q - p;

	if (ji == 0 && qp == 0) {
		cout << "POINT";
	}
	else if ((ji == 0 && qp > 0) || (ji > 0 && qp == 0)) {
		cout << "LINE";
	}
	else if (ji > 0 && qp > 0) {
		cout << "FACE";
	}
	else if (ji < 0 || qp < 0) {
		cout << "NULL";
	}

}