#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str1;
string str2;
int table[1001][1001];

int main() {
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else {
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}
	cout << table[str1.length()][str2.length()];
}