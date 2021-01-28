#include <iostream>

using namespace std;

int main() {
	int N;
	
	while (1) {
		cin >> N;
		if (N == 0) {
			return 0;
		}
		int table[6] = { 0, };
		int idx = 0;
		int flag = 0;
		while (N > 0) {
			table[idx] = N % 10;
			N /= 10;
			idx++;
		}

		for (int i = 0; i < idx; i++) {
			if (table[i] != table[idx - 1 - i]) {
				cout << "No" << endl;
				flag = 1;
				break;
			}
		}
		if(flag==0)
			cout << "yes"<<endl;
		
	}
	return 0;

}