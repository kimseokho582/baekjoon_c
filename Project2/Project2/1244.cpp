#include <iostream>
using namespace std;

int switchState[200] = { 0, };
int genderNum[][3] = { 0, };

int times;
void calc(int n,int i) {
	if (genderNum[i][0] == 1) {
		for (int j = 1; j <= n; j++) {
			if (j % genderNum[i][1] == 0)
				switchState[j] = !switchState[j];
		}
	}
	else if (genderNum[i][0] == 2) {
		int femaleNum = genderNum[i][1];
		for(int i=0;i<n/2+1;i++){


			if (switchState[femaleNum - i] == switchState[femaleNum + i]) {
				if (i == 0) {
					switchState[femaleNum] = !switchState[femaleNum];
				}
				else {
					switchState[femaleNum - i] = !switchState[femaleNum - i];
					switchState[femaleNum + i] = !switchState[femaleNum + i];
				}

			}
			else if (switchState[femaleNum - i] != switchState[femaleNum + i])
				break;

		}
	}

}


int main() {
	int n;  cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> switchState[i];
	}
	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> genderNum[i][0] >> genderNum[i][1];
		calc(n,i);
	}
	for (int i = 1; i <= n; i++) {
		cout<< switchState[i]<<" ";
		if (i % 20 == 0)
			cout << endl;
	}
}