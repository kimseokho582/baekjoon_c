#include <iostream>
using namespace std;

int main() {
	int times; cin >> times;
	int a[1234561] = { 0,1 };
	for (int i = 0; i < times; i++) {
		int num; cin >> num;
		for (int j = 2; j <= num; j++)
			for (int q = 2; j * q <= num; q++)
				a[j * q] = 1;
		int part1 = num / 2;
		int part2 = num / 2;
		for (int k = 2; k <= num; k++) {
			if (part1 + part2 == num && !a[part1] && !a[part2]) {
				cout << part1 << " " << part2 << endl;
				break;
			}
			part1--;
			part2++;
		}
	}

}