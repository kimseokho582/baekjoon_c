#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
	string str[6];
	for (int i = 0; i < 5; i++) {
		 cin >> str[i];
	}
	for (int j = 0; j < 15; j++) {
		for (int i = 0; i < 5; i++) {
			if (str[i].size() < j)continue;

			if(str[i][j]!=NULL)cout << str[i][j];
		}
	}
	
}