#include <iostream>

using namespace std;

int N, temp, answer = 0;
int table[100000];
int leftc[100000];         
int rightc[100000];       

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> table[i];
        temp += table[i];
        leftc[i] = temp;
    }
    for (int i = 0; i < N; i++)
    {
        rightc[i] = temp;
        temp -= table[i];
    }

    temp = 0;
    for (int i = 1; i < N - 1; i++)  
    {
        if (leftc[N - 1] - leftc[i] - table[i] > temp)     
        {
            temp = leftc[N - 1] - leftc[i] - table[i];
        }
    }
    answer = max(answer, temp + rightc[0] - table[0]);

    temp = 0;
    for (int i = N - 2; i >= 1; i--) 
    {
        if (rightc[0] - rightc[i] - table[i] > temp) 
        {
            temp = rightc[0] - rightc[i] - table[i];
        }
    }
    answer = max(answer, temp + rightc[0] - table[N - 1]);

    temp = 0;
    for (int i = 1; i < N - 1; i++) 
    {
        if (leftc[i] + rightc[i] > temp)           
        {
            temp = leftc[i] + rightc[i];
        }
    }
    answer = max(answer, temp - table[0] - table[N - 1]);

    cout << answer << endl;
}