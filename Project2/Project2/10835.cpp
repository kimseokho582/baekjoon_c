#include <iostream>
#include <algorithm>
using namespace std;

int cardLeft[2001];
int cardRight[2001];
int score[2001] = { 0, };
int N;
int idxLeft = 0, idxRight = 0;
int score = 0, scoreMax = 0;


void calc(int idxLeft, int idxRight) {
	for (int i = idxLeft; i < N; i++) {
		cout << cardLeft[i] << " ";
	}cout << endl;
	for (int i = idxRight; i < N; i++) {
		cout << cardRight[i] << " ";
	}cout << endl;

	if (idxLeft == N || idxRight == N) {
		int sum = 0;
		for (int i = 0; i < N; i++) {

		}
		return;
	}
	
	if (cardLeft[idxLeft] <= cardRight[idxRight]) {
		idxLeft++;
		calc(idxLeft, idxRight);
		idxLeft--;
		
		score[idxRight] = 0;

		idxLeft++;  idxRight++;
		calc(idxLeft, idxRight);
		idxLeft--; idxRight--;
	}
	else {
		score[idxRight] = cardRight[idxRight];
		idxRight++;
		calc(idxLeft, idxRight);
	}

}


int main() {
	cin >> N;
	for (int j = 0; j < N; j++) cin >> cardLeft[j];
	for (int j = 0; j < N; j++) cin >> cardRight[j];

	calc(idxLeft, idxRight);
	cout << "´ä"<<scoreMax << endl;
}
