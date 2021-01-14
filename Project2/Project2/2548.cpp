#include <iostream>

using namespace std;

int table[20001];
int tableSum[20001];
int N;	

void calc(int n,int index) {
	for (int i = 0; i < N; i++) {
		tableSum[index] += abs(n - table[i]);
	}
	
}

int main() {
	int min = 200000000;
	int ans = 0;
	int minIndex = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> table[i];
	}
	for (int i = 0; i < N; i++) {
		calc(table[i],i);
	}
	for (int i = 0; i < N; i++) {
		if (min > tableSum[i]) {
			min = tableSum[i];
			minIndex = i;
			ans = table[i];
		}
		else if (min == tableSum[i]) {
			if (table[i] > table[minIndex]) {
				min = tableSum[minIndex];
				ans = table[minIndex];
			}
			else if (table[i] < table[minIndex]) {
				min = tableSum[i];
				ans = table[i];
			}
		}
	}
	cout << ans;
	
}