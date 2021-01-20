#include <iostream>
using namespace std;

int table[10001];

int main() {
	int N; cin >> N;
	int min = 0, max = 0, mid;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> table[i];
		if (max < table[i])
			max = table[i];
		sum += table[i];
	}

	
	int budget; cin >> budget;
	if (sum <= budget) {
		cout << max;
		return 0;
	}
	else {
		while (min+1<max) {

			mid = (max + min) / 2;
			sum = 0;
			for (int i = 0; i < N; i++) {
				if (table[i] >= mid) {
					sum += mid;
				}
				else {
					sum += table[i];
				}
			}
			if (sum <= budget) {
				min = mid;
			}
			else {
				max = mid;
			}
		
		}
		cout << min;
	}
	return 0;
}