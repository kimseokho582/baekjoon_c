#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	float* p = new float[N];
	float large = 0, max = 0;
	int i = 0;

	for (; i < N; i++) {
		cin >> p[i];
		if (large < p[i])
			large = p[i];
	}
	for (i = 0; i < N; i++) {
		p[i] = p[i] / large * 100;
		max += p[i];
	}
	cout << max / N;
}