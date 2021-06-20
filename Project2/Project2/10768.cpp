#include <iostream>
using namespace std;
 
int main() {
    int n, m; cin >> n >> m;

    n > 2 || (n == 2 && m > 18) ? cout << "After" : (n == 2 && m == 18 ? cout << "Special" : cout << "Before");
}