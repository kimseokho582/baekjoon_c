#include <iostream>
using namespace std;

string cmp[9] = {
	"000000",
	"001111",
	"010011",
	"011100",
	"100110",
	"101001",
	"110101",
	"111010"
};

int main() {
	int n; cin >> n;
	string ans = "";
	for (int i = 0; i < n; i++) {
		string str="";
		for (int j = 0; j < 6; j++) {
			char tmp; cin >> tmp;
			str += tmp;
		}
		int flag = 0;
		for (int j = 0; j < 8; j++) {
			int cnt = 0;
			for (int k = 0; k < 6; k++) {
				if (str[k] != cmp[j][k])cnt++;
			}

			if (cnt == 0 || cnt == 1) {
				ans += (65+j);
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			cout << i + 1 << endl;
			return 0;
		}

	}
	cout << ans;
}