#include <iostream>
#include <queue>
using namespace std;

queue<int>table;

int main() {

	int N, K; cin >> N >> K;

	for (int i = 1; i <= N; i++) table.push(i);
	cout << "<";
	while (!table.empty()) {
		for (int i = 0; i < K - 1; i++) {
			table.push(table.front());
			table.pop();
		}
		cout << table.front();
		table.pop();
		if(table.size())
			cout << ", ";
	}
	cout << ">";
}