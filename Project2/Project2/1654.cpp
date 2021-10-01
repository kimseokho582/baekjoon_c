#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>table;
int k, n;

int main() {
	 cin >> k >> n;
	 for (int i = 0; i < k; i++) {
		 int tmp; cin >> tmp;
		 table.push_back(tmp);
	}
	 int right = *min_element(table.begin(), table.end());
     int left = 1;
     int result = 0;
     while (left <= right) {
         int mid = (left + right) / 2;
         int cnt = 0;
         for (int i = 0; i < k; i++) {
             cnt += table[i] / mid;
         }
         if (cnt < n) {
             right = mid - 1;
         }
         else {
             left = mid + 1;
             result = mid;
         }

     }
     cout << result;
}

