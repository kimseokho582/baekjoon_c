#include <iostream>
#include <vector>

using namespace std;

vector<int> large;

vector<int> cal(vector<int> seq) {

    while (1) {
        if (seq[seq.size() - 2] - seq[seq.size() - 1] < 0) {
            return seq;
        }
        seq.push_back(seq[seq.size() - 2] - seq[seq.size() - 1]);
    }

}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> seq = cal({ n, i+1 });
        if (seq.size() > large.size()) {
            large = seq;
        }
    }

    cout << large.size() << endl;
    for (int ans : large) {
        cout << ans << " ";
    }
}