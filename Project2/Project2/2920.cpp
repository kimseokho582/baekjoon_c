#include <iostream>
#include <cstring>

using namespace std;

char asc[9] = {"12345678"};
char desc[9] = {"87654321"};
char table[9];
int main() {
	for (int i = 0; i < 8; i++) {
		cin >> table[i];
	}

	if (!strcmp(asc,table))
		cout << "ascending";
	else if (!strcmp(desc,table))
		cout << "descending";
	else
		cout << "mixed";
}