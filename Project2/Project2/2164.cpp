#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> table;
int N;
int main() {
	//cin >> N;
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++)
		table.push(i);

	while (table.size() != 1) {
		table.pop();
		table.push(table.front());
		table.pop();
	}
	cout << table.front();

}