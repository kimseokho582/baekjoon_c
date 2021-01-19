#include <iostream>

using namespace std;

int A[11], B[11];
char result[11];
int scoreA=0, scoreB=0;

int main() {
	for (int i = 0; i < 10; i++) cin >> A[i];
	for (int i = 0; i < 10; i++) cin >> B[i];

	for (int i = 0; i < 10; i++) {
		if (A[i] > B[i]) {
			scoreA += 3;
			result[i] = 'A';
		}
		else if (A[i] < B[i]) {
			scoreB += 3;
			result[i] = 'B';
		}
		else if (A[i] == B[i]) {
			scoreA++;
			scoreB++;
			result[i] = 'D';
		}
	}
	cout << scoreA << " " << scoreB << endl;
	if (scoreA > scoreB)
		cout << 'A';
	else if (scoreA < scoreB)
		cout << 'B';
	else if (scoreA == scoreB) {
		for (int i = 9; i >= 0; i--) {
			if (result[i] != 'D') {
				cout << result[i];
				return 0;
			}
		}
		cout << 'D';
	}

}