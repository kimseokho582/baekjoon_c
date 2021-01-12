#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char dial[20] = { 0, }; cin >> dial;
	int count = 0;

	for (int i = 0; i < strlen(dial); i++) {
		if (dial[i] >= 65 && dial[i] <= 67)
			count = count + 2;
		else if (dial[i] >= 68 && dial[i] <= 70)
			count = count + 3;
		else if (dial[i] >= 71 && dial[i] <= 73)
			count = count + 4;
		else if (dial[i] >= 74 && dial[i] <= 76)
			count = count + 5;
		else if (dial[i] >= 77 && dial[i] <= 79)
			count = count + 6;
		else if (dial[i] >= 80 && dial[i] <= 83)
			count = count + 7;
		else if (dial[i] >= 84 && dial[i] <= 86)
			count = count + 8;
		else
			count = count + 9;
	}
	cout << count + strlen(dial);
}