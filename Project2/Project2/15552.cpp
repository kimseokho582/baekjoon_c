#include <iostream>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a; cin >> a;
	int* p = new int[a];
	for (int i = 0; i < a; i++) {
		int b; cin >> b;
		int c; cin >> c;
		p[i] = b + c;
	}
	for (int i = 0; i < a; i++) {
		cout << p[i] << '\n';
	}

}
