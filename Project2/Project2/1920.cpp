#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int>A;

int main() {
	//cin >> N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;// cin >> tmp;
		scanf_s("%d", &tmp);
		A.push_back(tmp);
	}
	sort(A.begin(), A.end());

	//cin >> M;
	scanf_s("%d", &M);
	int tmp;
	for (int i = 0; i < M; i++) {
		 //cin >> tmp;
		 scanf_s("%d", &tmp);
		
		 if (A[N - 1] >= tmp) {
			 if (A[lower_bound(A.begin(), A.end(), tmp) - A.begin()] != tmp)
				 cout << 0 << " ";
			 else
				 cout << 1 << " ";
		 }
		 else
			 cout << 0 << " ";
	}

}

