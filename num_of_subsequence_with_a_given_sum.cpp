#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int solve(int arr[], int n, int sum)
{
    if (n == 0)
        return 0;
    if (sum == 0)
        return 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
 
    return t[n][sum];
}

int main()
{
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    cout << "Enter the array elements one by one: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the sum: ";
    int sum;
    cin >> sum;

    // initialize the matrix t
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (n == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }

    int ans = solve(arr, n, sum);
    cout << ans;

    return 0;
}