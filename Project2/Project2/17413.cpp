#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string S; getline(cin, S);
	int tagCheck = 0;
	stack<char>word;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '<') {
			while (!word.empty()) {
				cout << word.top();
				word.pop();
			}
			tagCheck = 1;
			cout << S[i];
		}
		else if (S[i] == '>') {
			tagCheck = 0;
			cout << S[i];
		
		}
		else if (S[i] == ' ') {
			if (tagCheck != 1) {
				while (!word.empty()) {
					cout << word.top();
					word.pop();
				}
			}
			cout << S[i];
		}
		else {
			if (tagCheck == 0) {
				word.push(S[i]);
			}
			else {
				cout << S[i];
			}
		}
	}
	while (!word.empty()) {
		cout << word.top();
		word.pop();
	}
}