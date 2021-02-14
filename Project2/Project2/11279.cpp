#include <iostream>
#include <queue>

using namespace std;

priority_queue<int>table;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	int n = N;
	while (N-- > 0) {
		int tmp; cin >> tmp;
		if (tmp != 0) {
			table.push(tmp);
		}
		else {
			if (!table.empty()) {
				cout  << table.top() <<  "\n";
				table.pop();
			}
			else cout <<0 << "\n";
		}
	}

}