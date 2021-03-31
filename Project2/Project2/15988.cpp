#include <iostream>
#include <vector>
using namespace std;

int large(int x, int y) { return x > y ? x : y; }

vector<long long>test;
vector<long long>table(1000002);
int main() {
	int Big = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		test.push_back(tmp);
		Big = large(Big, tmp);
	}

	table[1] = 1; table[2] = 2; table[3] = 4;

	for (int i = 4; i <= Big; i++) table[i] = (table[i - 1] + table[i - 2] + table[i - 3]);

	for (int i = 0; i < test.size(); i++) cout << table[test[i]] % 1000000009 << endl;
}