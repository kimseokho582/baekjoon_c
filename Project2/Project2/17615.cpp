#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, check = 0, cnt = 0;
int ans = 999999999;
int main() {
	cin >> n;
	string str; cin >> str;
	

	for (int i = 0; i < n; i++) { 
		if (str[i] == 'B')check = 1;
		if (check == 1 && str[i] == 'R')cnt++;
	}
	ans = min(cnt, ans);
	check = 0; cnt = 0;

	for (int i = 0; i < n; i++) {
		if (str[i] == 'R')check = 1;
		if (check == 1 && str[i] == 'B')cnt++;
	}
	ans = min(cnt, ans);
	check = 0; cnt = 0;

	for (int i = n-1; i >=0; i--) { 
		if (str[i] == 'B')check = 1;
		if (check == 1 && str[i] == 'R')cnt++;
	}
	ans = min(cnt, ans);
	check = 0; cnt = 0;

	for (int i = n - 1; i >= 0; i--) { 
		if (str[i] == 'R')check = 1;
		if (check == 1 && str[i] == 'B')cnt++;
	}
	ans = min(cnt, ans);
	
	cout << ans;
}