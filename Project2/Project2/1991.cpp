#include <iostream>
#include <queue>

using namespace std;
vector<pair<char,char>>table(66+26);
queue<char>orderSearch;

void pre(int idx) {
	int left = (int)table[idx].first;
	int right = (int)table[idx].second;
	if ((char)idx == '.') {
		return;
	}
	orderSearch.push((char)idx);
	pre(left);
	pre(right);
}

void in(int idx) {
	int left = (int)table[idx].first;
	int right = (int)table[idx].second;
	if ((char)idx == '.') {
		return;
	}
	in(left);
	orderSearch.push((char)idx);
	in(right);
}
void post(int idx) {
	int left = (int)table[idx].first;
	int right = (int)table[idx].second;
	if ((char)idx == '.') {
		return;
	}
	post(left);
	post(right);
	orderSearch.push((char)idx);
}




int  main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		char root, left, right; cin >> root >> left >> right;
		table[(int)root]=make_pair(left,right);
	}
	pre(65);
	while(!orderSearch.empty()) {
		cout<<orderSearch.front();
		orderSearch.pop();
	}
	in(65);
	cout << endl;
	while (!orderSearch.empty()) {
		cout << orderSearch.front();
		orderSearch.pop();
	}

	post(65);
	cout << endl;
	while (!orderSearch.empty()) {
		cout << orderSearch.front();
		orderSearch.pop();
	}

}