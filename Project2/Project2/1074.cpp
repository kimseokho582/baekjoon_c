#include <iostream>

using namespace std;

int N, r, c;
int ans;
void calc(int cN, int cr, int cc) {
	if (r == cr&&c == cc){
		cout<< ans;
		return;
	}

	if (r < cN + cr && r >= cr && c < cc + cN && c >= cc) {
		
		calc(cN / 2, cr, cc);
		calc(cN / 2, cr, cc + cN / 2);
		calc(cN / 2, cr + cN / 2, cc);
		calc(cN / 2, cr + cN / 2, cc + cN / 2);
	}
	else {
		ans +=  cN * cN;
	}
}

int main() {
	
	cin >> N >> r >> c;

	calc((1 << N),0, 0);
	

}