#include <iostream>
using namespace std;


int main() {
	int n, c; cin >> n >> c;
	int A = n, B = n;
	int sum = n*n;
	while (c--) {
		int a, b; cin >> a >> b;
		if (a > A || b > B)continue;
		int tmp1=0, tmp2=0;
	    tmp1 = a * B;
		tmp2 = A * b;
		
		if (tmp1 >= tmp2) {
			A = a;
		}
		else {
			B = b;
		}
		sum = A * B;

	}
	cout << sum;
}