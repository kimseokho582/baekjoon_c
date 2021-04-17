#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string str; cin >> str;
    long long nine = 0;
	int num = str.length();
	
	for (int i = 1; i < num ; i++) {
		nine += pow(10, i - 1) * 9 * i;
	}
    nine += (stoi(str) - pow(10, num - 1) + 1) * num;
    cout << nine;
}
