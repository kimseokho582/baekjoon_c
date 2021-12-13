#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct box {
	int start;
	int end;
	int weight;
};
int N, C;
int M;
int x, y, weight;
int result;
int truck[2001];
bool compare(box& lhs, box& rhs) {
	if (lhs.end < rhs.end) return true;
	else if (lhs.end == rhs.end) {
		if (lhs.start <= rhs.start) return true;
		else return false;
	}
	else return false;
}

int main() {
	cin >> N >> C;
	cin >> M;
	vector<box> sendbox(M);
	for (int i = 0; i < M; i++) {
		cin >> sendbox[i].start >> sendbox[i].end >> sendbox[i].weight;
	}
	sort(sendbox.begin(), sendbox.end(), compare);

	for (int i = 0; i < M; i++) {
		int cnt = 0;
		for (int j = sendbox[i].start; j < sendbox[i].end; j++) {
			cnt = max(truck[j], cnt);
		}
		result += min(sendbox[i].weight, C - cnt); 
		for (int j = sendbox[i].start; j < sendbox[i].end; j++) { 
			truck[j] += min(sendbox[i].weight, C - cnt);
		}
	}
	cout << result << "\n";
	return 0;
}