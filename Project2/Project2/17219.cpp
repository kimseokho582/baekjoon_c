#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	map<string, string>mset;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		mset.insert({ a,b });
	}
	for (int i = 0; i < m; i++) {
		string tmp; cin >> tmp;
		cout << mset[tmp]<<"\n";
	}
}