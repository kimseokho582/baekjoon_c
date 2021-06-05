#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char str[12];
int check[10] = { 0, };
int n;
string small = "999999999", large = "0";

void calc(string num,int cnt,int pre) {
	if (cnt == n+1) {
		small = min(num, small);
		large = max(num, large);
		return;
	}
	
	for (int i = 0; i <= 9; i++) {
		if (cnt == 0&&check[i]!=1) {
			
			num.clear();
			num += i + '0';
			check[i] = 1;
			calc(num, cnt + 1,i);
			check[i] = 0;
			num.pop_back();

		}
		else {
			if (str[cnt] == '<') {
				if (pre < i && check[i] != 1) {
					num += i + '0';
					check[i] = 1;
					calc(num, cnt + 1, i);
					check[i] = 0;
					num.pop_back();

				}
			}
			else {
				if (pre > i&& check[i] != 1) {
					num += i + '0';
					check[i] = 1;
					calc(num, cnt + 1, i);
					check[i] = 0;
					num.pop_back();

				}
			}
		}
	}
	return;

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
	}
	calc("",0,0);

	cout << large << endl << small;

}