#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<string>table;
int N;

bool cmp(string x, string y) {
	if (x.length() != y.length())
		return x.length() < y.length();
	return x < y;
	
}

int main() {
	cin >> N;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (find(table.begin(), table.end(), tmp) == table.end()) {
			table.push_back(tmp);
		}
		
	}
	
	sort(table.begin(), table.end(), cmp);

	for (int i = 0; i < table.size(); i++) {
		cout << table[i]<< "\n";
	}
}