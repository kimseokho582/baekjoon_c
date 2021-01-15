#include <iostream>

using namespace std;

int table[100000];
int N;

int main() {

	cin >> N;
	int left = 0;
	int right = N - 1;

	for (int i = 0; i < N; i++) {
		cin >> table[i];
	}

	int compare = abs(table[0] + table[N - 1]);
	int ans1 = table[0], ans2 = table[N - 1];

	

	while (left < right) {
		if (compare>abs(table[left] + table[right])) {
			compare = abs(table[left] + table[right]);
			ans1 = table[left];
			ans2 = table[right];
			
		}

		if (table[left] + table[right] > 0) {
			right--;
		}
		else{
			left++;
		}

	}
	cout << ans1 << " " << ans2;

}