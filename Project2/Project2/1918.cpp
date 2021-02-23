#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string formula; cin >> formula;
	string ans;
	stack<char>operatorStack;

	for (int i = 0; i < formula.size(); i++) {
		if (formula[i] >= 'A' && formula[i] <= 'Z') {
			ans +=formula[i];
		}
		else {
			if (formula[i] == '*' || formula[i] == '/') {
				while (!operatorStack.empty() && (operatorStack.top() == '*' || operatorStack.top() == '/')) {
					ans += operatorStack.top();
					operatorStack.pop();
				}
				operatorStack.push(formula[i]);
			}
			else if (formula[i] == '+' || formula[i] == '-') {
				while (!operatorStack.empty() && operatorStack.top()!='(') {
					ans += operatorStack.top();
					operatorStack.pop();
				}
				operatorStack.push(formula[i]);
			}
			else if (formula[i] == '(') {
				operatorStack.push(formula[i]);
			}
			else if (formula[i] == ')') {
				while (!operatorStack.empty() && operatorStack.top() != '(') {
					ans += operatorStack.top();
					operatorStack.pop();
				}
				operatorStack.pop();
			}
		}
	}
	while (!operatorStack.empty()) {
		ans += operatorStack.top();
		operatorStack.pop();
	}
	cout << ans;
	
}
