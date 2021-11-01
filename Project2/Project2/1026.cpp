#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int n; cin >> n;
	int rst = 0;
	vector<int>a, b;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		b.push_back(tmp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(),cmp);
	for (int i = 0; i < b.size(); i++) {
		rst += (a[i] * b[i]);
	}
	cout << rst;
}