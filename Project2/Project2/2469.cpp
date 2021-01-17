#include <iostream>
#include <vector>

using namespace std;

vector<string> ruler;
string top, bot,ans;
int N,line,hidden;

int main() {
	cin >> N >> line;
	for (int i = 0; i < N; i++) {
		top.push_back(65 + i);
	}
	cin >> bot;
	for (int i = 0; i < line; i++) {
		string tmp; cin >> tmp;
		ruler.push_back(tmp);
		if (ruler[i][0] == '?') hidden = i;
	}

	for (int i = 0; i < hidden; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (ruler[i][j] == '-') {
				swap(top[j], top[j + 1]);
			}
		}
	}
	for (int i = line - 1; i > hidden; i--) {
		for (int j = 0; j < N - 1; j++) {
			if (ruler[i][j] == '-') {
				swap(bot[j], bot[j + 1]);
			}
		}
	}
	string ans;
	for (int i = 0; i < N - 1; i++) {
		if (top[i] == bot[i]) {
			ans.push_back('*');
		}
		else if (top[i + 1] == bot[i] && top[i] == bot[i + 1]) {
			ans.push_back('-');
			swap(top[i], top[i + 1]);
		}
		else {
			for (int i = 0; i < N - 1; i++) {
				cout << "x";
			}
			return 0;
		}
	}
	cout << ans;
}