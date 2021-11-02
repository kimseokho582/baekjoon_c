#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	while (n--) {
		int x1, y1, x2, y2, x3, y3, x4, y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        double a = x2 - x1, b = y2 - y1, c = x4 - x3, d = y4 - y3;
        if (a * d - b * c) {
            double m = (d * (x3 - x1) - c * (y3 - y1)) / (a * d - b * c);
            cout << fixed;
            cout.precision(2);
            cout <<"POINT "<< a * m + x1 << " " << b * m + y1 << endl;
        }
        else {
            ((x3 - x1) * b - (y3 - y1) * a) ? cout << "NONE" : cout << "LINE";
            cout << endl;
        }
	}
}
