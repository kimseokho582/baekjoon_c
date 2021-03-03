#include <iostream>
using namespace std;

int N, M;
int table[9];
int check[9];

void search(int num, int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << table[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= N; i++)
    {
        if (!check[i])
        {
            check[i] = 1;
            table[cnt] = i;
            search(i + 1, cnt + 1);
            check[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    search(1, 0);
}