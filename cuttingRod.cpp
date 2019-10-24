#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <string>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int cutRod(int price[], int n){
    int val[n + 1];
    string res[n + 1];
    val[0] = 0;
    res[0] = "";

    int i, j;

    for (i = 1; i <= n; i++)
    {
        int max_val = INT_MIN;
        string temp = "";
        for (j = 0; j < i; j++)
            if (max_val < price[j] + val[i - j - 1])
            {
                max_val = max(max_val, price[j] + val[i - j - 1]);
                if (temp == "")
                {
                    temp = to_string(j + 1);
                }
                else
                {
                    temp =to_string(j + 1) + "," + res[i - j - 1] ;
                }
            }
            else
            {
                max_val = max(max_val, price[j] + val[i - j - 1]);
            }
        res[i] = temp;
        val[i] = max_val;
    }
    cout << res[n] << endl;
    return val[n];
}

int main(){
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20, 1, 1, 1, 1, 1, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << cutRod(arr, size);
    return 0;
}