#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int>>frame;
int frameNum;
int recommend;

void calc(int n) {
	if (frame.size() == 0) {
		frame.push_back(pair<int, int>(n, 1));
	
		return;
	}
	if (frame.size() < frameNum) {
		for (int i = 0; i < frame.size(); i++) {
			if (frame[i].first == n) {
				frame[i].second++;
			
				return;
			}
		}
		frame.push_back(pair<int, int>(n, 1));
		return;

	}
	else {
		for (int i = 0; i < frame.size(); i++) {
			if (frame[i].first == n) {
				frame[i].second++;
			
				return;
			}
		}
		int min = 1001;
		int minindex = 0;
		for (int i = 0; i < frame.size(); i++) {	
			if (min > frame[i].second) {
				min = frame[i].second;
				minindex = i;
				}
		}
		frame.erase(frame.begin() + minindex, frame.begin() + minindex + 1);
		frame.push_back(pair<int, int>(n, 1));
		}
}


int main() {
	cin >> frameNum;
	cin >> recommend;
	int tmp;
	for (int i = 0; i < recommend; i++) {
		cin >> tmp;
		calc(tmp);
	}
	sort(frame.begin(), frame.end());
	for (int i = 0; i < frame.size(); i++) {
		cout << frame[i].first << " ";
	}


}
