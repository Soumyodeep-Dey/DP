#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

bool subsetSum(int arr[], int n, int sum)
{
    if (n == 0)
        return false;
    if (sum == 0)
        return true;

    // i = 1 to n as if i = 0 arr[i-1] becomes invalid and j = 1 to sum
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
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the array elements one by one: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // calculating the sum 
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    // initialization of maatrix t
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

    if (sum % 2 != 0)
    {
        cout << "FALSE";
    }

    else if (sum % 2 == 0)
    {
        bool ans = subsetSum(arr, n, sum / 2);
        ans ? cout << "TRUE" : cout << "FALSE";
    }

    return 0;
}