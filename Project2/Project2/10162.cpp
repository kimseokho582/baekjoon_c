#include <iostream>

using namespace std;

int main() {
	int T; cin >> T;
	int A = 0, B = 0, C = 0;
	while (T>9) {
		while (1) {
			if (T >= 300) {
				T -= 300;
				A++;
			}
			else
				break;
		}
		while (1) {
			if (T >= 60) {
				T -= 60;
				B++;
			}
			else
				break;
		}

		if (T >= 10) {
				T -= 10;
				C++;
			
			}
	}


	if (T == 0) {
		cout << A << " " << B << " "<<C;

	}
	else {
		cout << "-1";
	}

}