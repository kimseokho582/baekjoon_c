#include <iostream>
using namespace std;

int table[100001];
int N;
int seq;
int sum;


int main() {
	cin >> N>>seq;
	
	for (int i = 0; i < N; i++) cin >> table[i];

	int j = 0;
	for (int i = j; i < j +seq; i++)
		sum += table[i];
	int large = sum;

	while (1) {
		sum -= table[j];
		if (j + seq >= N)
			break;
		sum += table[j + seq];
		if (large < sum)
			large = sum;
		j++;
	}

	cout << large;
}