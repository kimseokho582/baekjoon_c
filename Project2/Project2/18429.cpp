#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int>table(n);
	vector<int>index(n);
	int answer = 0;
	for (int i = 0; i <n; i++) {
		cin >> table[i];
		index[i] = i;
	}
	do {
		vector<int>tmp;
		for (int i = 0; i < index.size(); i++) {
			tmp.push_back(table[index[i]]);
		}

		int sum = 0;
		int flag = 0;
		for (int i = 0; i < n; i++) {
			sum += (tmp[i]-k);
			if (sum < 0) {
				flag = 1;
				break;
			}

		}
		if (flag == 0)answer++;
	} while(next_permutation(index.begin(), index.end()));
	cout << answer;
}