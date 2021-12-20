#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int  main() {
	vector<int>v;
	int n; cin >> n;
	int table[8001] = { 0, };
	int sum = 0;
	int cmp = -4001;
	int most = 0;
	bool second = false;
	for(int i=0;i<n;i++) {
		int tmp; cin >> tmp;
		table[tmp + 4000]++;
		sum += tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v[n - 1] + 4001; i++) {
		if (table[i] == 0)continue;
		if (table[i] == cmp) {
			if (second) {
				most = i - 4000;
				second = false;
			}
		}
		if (table[i] > cmp) {
			cmp = table[i];
			most = i - 4000;
			second = true;
		}

	}

	cout << round((float)sum/n)<< endl;
	cout << v[n / 2] << endl;
	cout << most<<endl;
	cout << v[n - 1] - v[0] << endl;
}
