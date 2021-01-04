#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>table(1000);
pair<int, int>big;
int bigindex = 0;
int n;
bool tmpsort(pair<int, int>x, pair<int, int>y) {
		return x.first > y.first;
	
}

int right() {
	int rightbig = table[0].second;
	int rightsize = 0;
	for (int i = 0; i < bigindex; i++) {
		if (table[i].second >= rightbig)
			rightbig = table[i].second;
		rightsize += (table[i].first - table[i + 1].first) * rightbig;
	}
	return rightsize;
}

int left() {
	int leftbig = table[n - 1].second;
	int leftsize = 0;
	for (int i = n-1; i > bigindex; i--) {
		if (table[i].second >= leftbig)
			leftbig = table[i].second;
		leftsize += (table[i - 1].first - table[i].first) * leftbig;
	}
	return leftsize;

}

int main() {
	cin >> n;
	big.first = 0;
	big.second = 0;
	for (int i = 0; i < n; i++) {
		cin >> table[i].first >> table[i].second;
	}
	sort(table.begin(),table.end(),tmpsort);
	for (int i = 0; i < n; i++) {
		if (big.second < table[i].second) {
			big = table[i];
			bigindex = i;
		}

	}

	cout<<right()+left()+big.second;

	
}