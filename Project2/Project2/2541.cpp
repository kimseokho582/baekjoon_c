#include <iostream>
#include <cmath>
using namespace std;

int x, y;
int main() {
   
    cin >> x >> y;
    int check;
    if (x == y) check = 0;
    else if (x > y) check = 1;
    else check = -1;
    int d = abs(x - y);
    while (d > 0 && d % 2 == 0) d /= 2;
    for (int i = 0; i < 5; i++) {
        cin >> x >> y;
        int flag = 0;
        if (check == 0 && x == y) flag = 1;
        else if (check * (x - y) > 0 && abs(x - y) % d == 0) flag = 1;
        flag ? cout << 'Y' : cout << 'N';
        cout << endl;
    }
}