#include <iostream>
using namespace std;

int  main() {
	int S, E, M; cin >> S >> E >> M;
	int i = 1,s=1,e=1,m=1;
	while (1) {
		s % 15 == 0 ? s = 15 : s %= 15;
		e % 28 == 0 ? e = 28 : e %= 28;
		m % 19 == 0 ? m = 19 : m %= 19;
		if (s == S && e  == E && m == M) {
			cout << i;
			return 0;
		}
		i++, s++, e++, m++;
	}
}