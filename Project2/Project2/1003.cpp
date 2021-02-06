#include <stdio.h>

int cnt0, cnt1;
int table[41] = { 0,1, };
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    if (table[n]!=0) 
        return table[n];
    else
        return table[n] = fibonacci(n - 1) + fibonacci(n - 2);
  
}

int main() {
    int N; scanf_s("%d", &N);

    for (int i = 0; i < N; i++) {
        int num; scanf_s("%d", &num);
        if (num == 0) {
            printf("1 0\n");
        }
        else {
        fibonacci(num);
        printf("%d %d\n", table[num - 1], table[num]);

        }
        
    }
}