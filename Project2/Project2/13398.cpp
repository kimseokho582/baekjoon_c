#include <iostream>
using namespace std;
int N, num,num2, ans,ans2;
int large(int x, int y) {
	return(x > y ? x : y);
}

int main() {
	cin >> N >> num;
	ans=num2 = num;
	for (int i = 1; i < N; i++) {
		int in; cin >> in;
		num2 = large(num, num2 + in);
		num = large(in, in + num);
		ans = large(num2,large(num, ans));
		
	}
	cout << ans;
}