#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int a; cin >> a;
	for (int i = 0; i < a; i++) {
		float count = 0;
		int b; cin >> b;
		int* p = new int[b];
		int sum = 0;
		for (int i = 0; i < b; i++) {
			cin >> p[i];
			sum += p[i];
		}
		for (int i = 0; i < b; i++) {
			if ((int)sum / b < p[i])
				count++;
		}
		cout << round(count / b * 100 * 1000) / 1000 << "%\n";
		//printf("%.3f%%\n", (float)count / b * 100);
	}
}