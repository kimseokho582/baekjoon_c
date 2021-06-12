#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	!(n % 5) ? cout << n / 5 : cout << n / 5 + 1;
}