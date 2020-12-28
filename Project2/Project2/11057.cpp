#include <iostream>
#include<cmath>
using namespace std;

#define MAX_SIZE 1001
int table[MAX_SIZE] = { 0, };
int ccount = 0;
void calc(int n) {
	for (int i = 0; i < pow(10, n); i++) {
		int flag = 0;
		for (int j = 1; j <= n; j++) {
			int num = i;
			num = num/pow(10, j-1);
			table[n-j] = num % 10;
			
		}
		for (int j = 0; j < n-1; j++) {
			if (table[j] > table[j + 1]) {
				break;
			}
			else
				flag++;
		}
		if (flag == n - 1)
			ccount++;
	}

}

int main() {
	int n; cin >> n;
	calc(n);
	cout<<ccount;
}