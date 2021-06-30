#include <iostream>
using namespace std;

int main() {
	while (1) {
		int i, j, num; cin >> num;
		int count = 0;
		int a[1234571] = { 0,1 };
		if (num == 0)
			return 0;
		for (i = 2; i <= 2 * num; i++)
			for (j = 2; i * j <= 2 * num; j++)
				a[i * j] = 1;
		for (i = num + 1; i <= 2 * num; i++) {
			if (!a[i])
				count++;
		}
		cout << count << endl;
	}
}