#include <iostream>
#include<string>
#include <map>
#include <algorithm>

using namespace std;

map<string, int>table1;
map<int,string>table2;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string tmp; cin >> tmp;
		table1.insert(pair<string, int>(tmp, i));
		table2.insert(pair<int,string>(i,tmp));
	}
	for (int i = 0; i < M; i++) {
		string qus; cin >> qus;
		if (!(qus[0] >= 48 && qus[0] <= 57)) {
			cout << table1[qus]<<"\n";//숫자 출력
		}
		else {
			cout <<table2[stoi(qus)] << "\n";//문자 출력
		}
	}

}