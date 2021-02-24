#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string table[101][101] = {};

string intToStr(string a, string b) {
	int sum = 0;
	string result;
	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}


string calc(int n, int m) {
	if (n == m || m == 0)
		return "1";
	if (table[n][m] != "")
		return table[n][m];
	return table[n][m] = intToStr(calc(n - 1, m - 1), calc(n - 1, m));
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	cout << calc(n, m);
}