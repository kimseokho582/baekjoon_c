#include <iostream>

using namespace std;

int main() {
    int A, B; cin >> A >> B;
    int ans = 1;
    while (1) {

        if (B % 2 == 0) {
            B /= 2;
            ans++;
        }
        else if ((B - 1) % 10 == 0) {
            B /= 10;
            ans++;
        }
        else {
            cout << -1;
            return 0;
        }
        if (A == B) {
            cout << ans;
            return 0;
        }
        if (A > B) {
            cout << -1;
            return 0;
        }
    }
}