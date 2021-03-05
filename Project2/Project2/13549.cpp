#include<iostream>
#include<queue>
#include<algorithm>
#define SIZE_MAX 1000001
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>table;
int check[SIZE_MAX] = { 0, };
int main() {

    int N, K; cin >> N >> K;
    int point, time;
    check[N] = 1;
    table.push(make_pair(0, N));
    while (!table.empty()) {

        time = table.top().first;

        point = table.top().second;
        //cout << "point: " << point << " time: " << time << endl;
        if (point == K) {
            cout << time;
            return 0;
        }

        table.pop();
        if (point * 2 < SIZE_MAX && check[point * 2] == 0) {
            table.push({ time,point * 2 });
            check[point * 2] = 1;
        }
        if (point + 1 < SIZE_MAX && check[point + 1] == 0) {
            table.push({ time + 1,point + 1 });
            check[point + 1] = 1;
        }

        if (point - 1 >= 0 && check[point - 1] == 0) {
            table.push({ time + 1,point - 1 });
            check[point - 1] = 1;
        }


    }
}