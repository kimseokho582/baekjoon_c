#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_SIZE 20000+1


using namespace std;

int K, V, E;
vector<int> graph[MAX_SIZE];
int visited[MAX_SIZE];

void bfs(int start);
bool isBipartiteGraph();

void bfs(int start) {
    queue<int> q;
    int check = 1;

    visited[start] = check;
    q.push(start);
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (visited[now] == 1) {
            check = -1;
        }
        else if (visited[now] == -1) {
            check = 1;
        }

        int gsize = graph[now].size();
        for (int i = 0; i < gsize; i++) {
            int next = graph[now][i];
            if (!visited[next]) {
                visited[next] = check;
                q.push(next);
            }
        }
    }
}

bool isBipartiteGraph() {
    for (int i = 1; i <= V; i++) {
        int gsize = graph[i].size();
        for (int j = 0; j < gsize; j++) {
            int next = graph[i][j];
            if (visited[i] == visited[next]) {
                return 0;
            }
        }
    }
    return 1;
}


int main() {
    cin >> K;
    while (K--) {
        cin >> V >> E;
        for (int i = 0; i < E; i++) {
            int f, s; cin >> f >> s;
            graph[f].push_back(s);
            graph[s].push_back(f);
        }
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) { 
                bfs(i);
            
            }
        }

        if (isBipartiteGraph()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }


        for (int i = 0; i <= V; i++) {
            graph[i].clear();
        }
        memset(visited, false, sizeof(visited));
    }
    return 0;
}