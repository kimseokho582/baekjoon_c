#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T-- > 0) {
		multiset<int>table;
		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			char C; int tmp; cin >> C >> tmp;
			if (C == 'I') {
				table.insert(tmp);
			}
			else if (C == 'D') {
				if (!table.empty()) {
					if (tmp == 1) {
						table.erase(--table.end());
					}
					else if (tmp == -1) {
						table.erase(table.begin());
					}
				}
			}
		}
		if (!table.empty()) {
			cout << *(--table.end()) << " " << *table.begin() << "\n";
			
		}
		else
		{
			cout << "EMPTY" << "\n";
		}
	}
}