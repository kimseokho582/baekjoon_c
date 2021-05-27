#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

deque<int>shapeDir;
deque<int>cpDir[101];
vector<int>ans;

int  n, cnt = 0;

deque<int> rvs(deque<int>x) {
	for (int i = 0; i < n; i++) {
		if (x[i] == 1) x[i] = 3;
		else if (x[i] == 2)  x[i] = 4;
		else if (x[i] == 3)  x[i] = 1;
		else x[i] = 2;
	}
	reverse(x.begin(), x.end());
	return x;
}

int check(deque<int>x ,int idx) {
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (shapeDir[j] != x[j]) {
				break;
			}
			else {
				cnt++;
			}
		}

		if (cnt == n) {
			ans.push_back(idx);
			return 1;
		}
		x.push_back(x.front());
		x.pop_front();
	}
	return 0;


}

int main() {
	 cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		shapeDir.push_back(tmp);
		
	}
	int c; cin >> c;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			cpDir[i].push_back(tmp);
		}
		if (check(cpDir[i], i) == 1) {
			cnt++;
		}
		else {
			if (check(rvs(cpDir[i]), i) == 1) {
				cnt++;
			}
		}
			
	}
	cout << cnt<<endl;
	for (int i = 0; i < cnt; i++) {
		for (int x : cpDir[ans[i]])cout << x << " ";
		cout << endl;
	}

}