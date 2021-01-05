#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int>table;
vector<int>piece;
vector<int>pieceCalc;
int ans = 1;
int flag1 = 0;
int flag2 = 0;

void PieceCalc() {
	int tmp;
	if (piece.back() <= 2)
		if (piece.back() == 0) {
			pieceCalc.push_back(1);
		}
		else {
			pieceCalc.push_back(piece.back());
		}
	else {
		tmp = 2 + pow(2, piece.back() - 2) - 1;
		pieceCalc.push_back(tmp);
	}
	ans = ans * pieceCalc.back();
}

void Piece(int n) {
	if (n == 0 || n == table.size() - 2) {
		piece.push_back(table[n + 1] - table[n]);
	}
	else {
		piece.push_back(table[n + 1] - table[n] - 1);
	}
	if (flag1 == 1 && n == 0)
		piece.front() = piece.front() - 1;
	if (flag2 == 1 && n == table.size() - 2)
		piece.back() = piece.back() - 1;
	PieceCalc();
}

int main() {
	
	table.reserve(42);
	piece.reserve(40);
	pieceCalc.reserve(40);
	int seat; cin >> seat;
	int n; cin >> n;
	
	table.push_back(1);
	int tmp;
	for (int i = 0; i < n; i++) {
		 cin >> tmp;
		 if(tmp!=1&&tmp!=seat)
		 table.push_back(tmp);
		 else if (tmp == 1) {
			 flag1 = 1;
		 }
		 else if (tmp == seat) {
			 flag2 = 1;
		 }

	}
	table.push_back(seat);


	for (int x : table)
		cout << x << " ";
	cout << endl << table.size();

	for (int i = 0; i < table.size() - 1; i++) {
		Piece(i);
	}
	cout << endl;
	for (int x : piece)
		cout << x << " ";
	cout << endl;
	for (int x : pieceCalc)
		cout << x << " ";
	cout << endl;
	if (ans == 0)
		ans = 1;
	cout << ans;
}