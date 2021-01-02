#include <iostream>
using namespace std;


int table[1000][5] = { 0, };

int large = 0;

int main() {
	int n; cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> table[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = j + 1; k < 5; k++)
			{
				for (int l = k + 1; l < 5; l++)
				{
					if (large <= (table[i][j] + table[i][k] + table[i][l]) % 10) {
						large = (table[i][j] + table[i][k] + table[i][l]) % 10;
						ans = i;
					}
				}
			}
		}

	}
	cout << ans+1;

}