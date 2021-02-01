#include <iostream>

using namespace std;

int N;
int table[1000001];
int* ans;

void merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (table[i] <= table[j]) {
            ans[k++] = table[i++];

        }
        else
        {
            ans[k++] = table[j++];

        }

    }
    if (i > mid) {
        for (int q = j; q <= right; q++) {
            ans[k] = table[q];
            k++;
        }
    }
    else {
        for (int q = i; q <= mid; q++) {
            ans[k] = table[q];
            k++;
        }
    }
    for (int i = left; i <= right; i++)
        table[i] = ans[i];
}


void mergeSort(int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }


}

int main() {
    //cin >> N;
    scanf("%d", &N);
    ans = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> table[i];
    }

    mergeSort(0, N - 1);


    for (int i = 0; i < N; i++)
        cout << table[i] << " ";

}