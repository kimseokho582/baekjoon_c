#include <iostream>
#include <algorithm>
using namespace std;
int main(void) { 
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int K; cin >> K; int C; cin >> C;

	for (int c = 0; c < C; c++) {
		int M, N; cin >> M >> N; 
		if (M - N == 0) {
			cout << 1 << "\n";
			continue;
		} 
		int remainGames = K - max(M, N);
		int diff = abs(M - N); 
		if (M > N) {
			if (diff - remainGames <= 2) { 
				cout << 1 << "\n";
				continue; 
			} 
			cout << 0 << "\n";
			continue; 
		} 

		if (diff - remainGames <= 1) { 
			cout << 1 << "\n"; 
			continue;
		} 
		cout << 0 << "\n"; 
	}

}

