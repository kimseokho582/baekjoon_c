#include <iostream>

using namespace std;
int student[1000] = { 0, };
int table[1000][10];
int n;
void calc() {


	for (int k = 1; k <= n; k++) { //1번 학생부터 n번 학생까지 주인공
		for (int j = 1; j <= n; j++) { // 비교학생
			for (int i = 1; i <= 5; i++) { //1반 부터 5반까지	
				if (table[k][i] == table[j][i]) {
					student[k]++;
					break;
				}
			}
			
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> table[i][j];
		}
	}
	calc();
	int ans = 0;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < student[i]) {
			max = student[i];
			ans = i;
		}
	}

	cout << ans;
}