#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

bool solve(int arr[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    
    // i = 1 to n and j = 1 to sum
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
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
    int n, sum;
    cout << "Enter the number of elements and the target sum: ";
    cin >> n >> sum;

    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Initialize the matrix t with false where i == 0 and true where j == 0
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            if (j == 0)
            {
                t[i][j] = true;
            }
        }
    }

    solve(arr, n, sum) ? cout << "YES" : cout << "NO";

    return 0;
}