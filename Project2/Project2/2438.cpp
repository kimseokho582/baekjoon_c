#include <iostream>
using namespace std;
int main()
{
	int a; cin >> a;
	int i = 1;

	for (i; i <= a; i++) {
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}cout << '\n';
	}
}
