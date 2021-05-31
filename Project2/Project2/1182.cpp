#include <iostream>
#include <algorithm>
using namespace std;


int table[21];
int check[21];
int number[21];
int n, m,ans=0;

void calc(int cnt, int num,int limit) {
	if (cnt == limit) {
		int tmp = 0;
		for (int i = 0; i < cnt; i++) {
			tmp += table[i];
		}
		if (tmp == m)ans++;
		return;
	}
	for (int i = num; i < n; i++) {
		if (!check[i]) {
			check[i] = 1;
			table[cnt] = number[i];
			calc(cnt+1,i+1,limit);
			check[i] = 0;
		}
	}
}


int  main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	sort(number, number + n);
	for (int i = 1; i <= n; i++) {
		calc(0, 0,i);
	}
	cout << ans;
}