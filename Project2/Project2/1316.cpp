#include <iostream>
#include <cstring>
using namespace std;

int countt = 0;
void check(string dial);
int main() {
	int num; cin >> num;
	string dial;

	for (int i = 0; i < num; i++) {
		cin >> dial;
		check(dial);
	}
	cout << countt;
	return 0;
}

void check(string dial) {

	int size = dial.size();

	for (int i = 0; i < size - 2; i++) {
		if (dial[i] != dial[i + 1]) {
			for (int j = i + 2; j < size; j++) {
				if (dial[i] == dial[j])
					return;
			}
		}

	}
	countt++;
}
