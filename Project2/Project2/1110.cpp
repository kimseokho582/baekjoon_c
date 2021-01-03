#include <iostream>
using namespace std;

int main(void) {
    int a; cin >> a;
    int q;
    q = a;
    int count = 1;
    while (1) {
        int v2, v1, sum;
        if (q < 10)
            v2 = 0;
        else
            v2 = q / 10;
        v1 = q % 10;

        sum = v2 + v1;
        if (sum >= 10)
            sum = sum - 10;
        q = v1 * 10 + sum;
        if (a == q)
            break;
        count++;
    }cout << count;
}
