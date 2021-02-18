#include <iostream>
#include <queue>
using namespace std;

int table[1001][3];
queue<int>startr;
queue<int>startg;
queue<int>startb;
queue<int>rgbcheck;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> table[i][j];
		}
	}

	startr.push(table[0][0]);
	rgbcheck.push(0);

	for(int i=1;i<n;i++){
		for (int k = 0; k < 2; k++) {
			int sum = startr.front();
			int rgb = rgbcheck.front();
			startr.pop(); rgbcheck.pop();
			cout << "sum: " << sum << "rgb: " << rgb << endl;
			for (int j = 0; j < 3; j++) {
				if (j != rgb) {
					startr.push(table[i][j] + sum);
					rgbcheck.push(j);
					cout << "table[i][j]: " << table[i][j] << ", j: " << j << endl;
				}
			}
		}
	}
	while (!startr.empty()) {
		cout << startr.front()<<endl;
		startr.pop();
	}
}