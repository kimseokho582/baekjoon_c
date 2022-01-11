#include <iostream>
#include <string>
using namespace std;

int n, m, rst;
string str;

int main()
{
	cin >> n >> m >> str;

	for (int i = 0; i < m; i++) {
		if (str[i] == 'O') continue;
		int tmp = 0;
		while (str[i + 1] == 'O' && str[i + 2] == 'I') {
			tmp++;
			i += 2;
			if (tmp == n) {
				tmp--;
				rst++;
			}
		}
	}

	cout << rst;
}