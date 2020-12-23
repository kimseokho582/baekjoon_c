#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>row;
vector<int>col;
vector<int>width;
vector<int>height;
int x, y;
int large=0;
void divi(int dir,int num) {
	if (dir == 0)
		row.push_back(num);
	else if (dir == 1)
		col.push_back(num);
}

void calc() {
	for (int i = 1; i < row.size(); i++)
		width.push_back(row[i] - row[i - 1]);
	for (int i = 1; i < col.size(); i++)
		height.push_back(col[i] - col[i - 1]);
	for (int i = 0; i < width.size(); i++) {
		for (int j = 0; j < height.size(); j++) {
			if (width[i] * height[j] >= large)
				large = width[i] * height[j];
		}

	}

}
int main() {
	 cin >> x >> y;
	int times; cin >> times;
	int dir, num;
	for (int i = 0; i < times; i++) {
		cin >> dir >> num;
		divi(dir, num);
	}
	row.push_back(y);
	col.push_back(x);
	row.push_back(0);
	col.push_back(0);
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());
	calc();
	cout << large;
}