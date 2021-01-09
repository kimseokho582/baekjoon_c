#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int K;
vector<int>table;

void demical(int sum,int n) {
	sum /= n;
	if (sum % 10 >= 5) {
		sum += 10;
	}
	sum /= 10;
	cout << sum / 100 << "." << (sum / 10) % 10 << sum % 10 << endl;

}

void trimmed() {
	int sum = 0;
	for (int i = K; i < N - K; i++)
		sum += table[i];

	demical(sum, N - 2 * K);

}

void adjusted() {
	int sum=0;
	for (int i = 0; i < K; i++)
		sum += table[K];

	for (int i = K; i < N - K; i++)
		sum += table[i];

	for (int i = N - K; i < N; i++)
		sum += table[N - K - 1];


	demical(sum, N);
}

int main() {
	cin >> N; cin >> K;
	double tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		table.push_back(1000*tmp);
	}
	sort(table.begin(), table.end());
	trimmed();
	adjusted();
	
}