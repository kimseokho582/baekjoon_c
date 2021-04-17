#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;


vector<int>broken;
int numLength;
int N, M;
int small(int x, int y) {
	return(x < y ? x : y);
}
int calc(int n) {
	if (n < 0) { 
		return 0; 
	}
	if (n == 100) {
		return 1;
	}
	//cout << "n: " << n << endl;
	vector<int>table;
	while (1) {
		table.push_back(n % 10);
		n /= 10;
		if (n == 0) break;
	}
	numLength = table.size();
	for (int i = 0; i < numLength; i++) {
		for (int j = 0; j < broken.size(); j++) {
			if (table[i] == broken[j]) {
				return 0;
			}
		}
	}
	
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	 cin >> N >> M;
	if (N == 100) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < M; i++) {
		int tmp; cin >> tmp;
		broken.push_back(tmp);
	}

	int i = 0;
	while (1) {

		if (calc(N - i) == 1||calc(N+i)==1) {
			//cout << "i:" << i << endl;
			cout<<small(abs(100 - N), i + numLength);
			return 0;
		}
		i++;
	}
	
	
}