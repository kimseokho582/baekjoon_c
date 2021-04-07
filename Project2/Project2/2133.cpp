/*#include <iostream>

#define endl "\n"
#define MAX 35
using namespace std;

int N;
int DP[MAX];

void Input()
{
    cin >> N;
}

void Solution()
{
    if (N % 2 == 1)
    {
        cout << 0 << endl;
        return;
    }
    DP[0] = 1;
    DP[1] = 0;
    DP[2] = 3;
    for (int i = 4; i <= N; i = i + 2)
    {
        DP[i] = DP[i - 2] * DP[2];
        for (int j = i - 4; j >= 0; j = j - 2)
        {
            DP[i] = DP[i] + (DP[j] * 2);
        }
    }
    for (int i = 1; i <= 30; i++) {
        cout << DP[i] << endl;
    }


    //cout << DP[N] << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    Solve();

    return 0;
}*/
#include <iostream>

using namespace std;

int table[40];
int main() {
    int N; cin >> N;
    if (N % 2)
    {
        cout << 0;
        return 0 ;
    }
    table[2] = 3;
    for (int n = 4; n <= N; n += 2) {
        table[n] = table[n - 2] * 3;
        for (int i = n-4; i >0; i -= 2) {
            table[n] += table[i] * 2;
        }
        table[n] += 2;
    }



    cout << table[N];
   

}