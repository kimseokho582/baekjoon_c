#include <iostream>
using namespace std;

int main() {

	int h1, h2, m1, m2, s1, s2;

	int h, m, s;
	for (int i = 0; i < 3; i++) {
	cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

		if ((s2 - s1) >= 0)
			s = s2 - s1;
		else {
			s = s2 - s1 + 60;
			m2--;
		}
		if ((m2 - m1) >= 0)
			m = m2 - m1;
		else {
			m = m2 - m1 + 60;
			h2--;
		}
		h = h2 - h1;
		cout << h << " " << m << " " << s << endl;
	}
}