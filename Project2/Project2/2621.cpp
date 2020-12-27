#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector < pair<char, int>>table(5);
vector < vector<int>>sameNum(5, vector<int>(2, NULL));
vector<int>two;
int four, threetwoTH, threetwoTW;
int colorSort;
int numSort;
bool tmpsort(pair<char, int>x, pair<char, int>y) {
	return x.second < y.second; //오름차순
}
int colorCalc() {
	for (int i = 0; i < 4; i++) {
		if (table[i].first == table[i + 1].first) {
			if (i == 3)
				return 1;
		}
		else
			return 0;
	}

}

int numCalc() {

	for (int i = 0; i < 4; i++) {
		if (table[i].second + 1 == table[i + 1].second) {
			if (i == 3)
				return 1;
		}
		else
			break;
	}

	
	sameNum[0][0] = table[0].second;
	sameNum[0][1] = 1;
	int num = 0;
	for (int i = 1; i < 5; i++) {

		if (table[i - 1].second != table[i].second) {
			num = i;
			sameNum[i][0] = table[i].second;
			sameNum[i][1] = 1;
		}
		else {
			sameNum[num][1]++;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (sameNum[i][1] >= 4) {
			four = sameNum[i][0];
			return 2;
		}
	}
	int threeCount = 0;
	for (int i = 0; i < 5; i++) {
		if (sameNum[i][1] == 3) {
			threetwoTH = sameNum[i][0];
			threeCount++;
		}
	}
	int twoCount = 0;
	for (int i = 0; i < 5; i++) {
		if (sameNum[i][1] == 2) {
			twoCount++;
			if (threeCount == 1)
				threetwoTW = sameNum[i][0];
			else if (threeCount == 0)
				two.push_back(sameNum[i][0]);
		}
	}

	if (threeCount == 1 && twoCount == 1)
		return 3;
	if (threeCount == 1 && twoCount == 0)
		return 4;
	if (twoCount == 2)
		return 5;
	if (twoCount == 1 && threeCount == 0)
		return 6;

	return 0;


}

void calc() {
	colorSort = colorCalc();
	numSort = numCalc();

	if (colorSort == 1 && numSort == 1) {
		cout << table[4].second + 900;
		return;
	}
	else if (numSort == 2) {
		cout << four + 800;
		return;

	}
	else if (numSort == 3) {
		cout << threetwoTH * 10 + threetwoTW + 700;
		return;
	}
	else if (colorSort == 1) {
		cout << table[4].second + 600;
		return;
	}
	else if (numSort == 1) {
		cout << table[4].second + 500;
		return;
	}
	else if (numSort == 4) {
		cout << threetwoTH + 400;
		return;
	}
	else if (numSort == 5) {
		cout << two[1] * 10 + two[0] + 300;
		return;
	}
	else if (numSort == 6) {
		cout << two[0] + 200;
		return;
	}
	else
		cout << table[4].second + 100;
	return;
}




int main() {

	for (int i = 0; i < 5; i++) {
		cin >> table[i].first >> table[i].second;
	}
	sort(table.begin(), table.end(), tmpsort);

	calc();

}