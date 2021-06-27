#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<int>stk;
    for (int i = 0; i < s.length(); i++) {
        if (stk.empty() || stk.top() != s[i])stk.push(s[i]);
        else stk.pop();
    }
    stk.empty() ? answer = 1 : answer = 0;
    return answer;
}