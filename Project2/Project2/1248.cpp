#include <iostream>
#include <vector>
using namespace std;

char table[10][10];
vector<int>ans;
int n;

int check(int idx) {
	int sum = 0;
	for (int i = idx; i >= 0; i--){
		sum += ans[i];

		if (table[i][idx] == '+' && sum <= 0)	return 0;
		if (table[i][idx] == '0' && sum != 0)	return 0;
		if (table[i][idx] == '-' && sum >= 0)	return 0;
	}
	return 1;
}

void calc(int idx) {
	if (idx == n)
	{
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		exit(0);
	}


	for (int i = -10; i <= 10; i++)
	{

		ans.push_back(i);
		if (check(idx))
			calc(idx + 1);

		ans.pop_back();
	}
}

int  main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i <= j) {
				cin >> table[i][j];
			}
			else {
				table[i][j] = 'x';
			}
		}
	}
	calc(0);
}