#include <bits/stdc++.h>
using namespace std;

bool t[1001][1001];

void subsetSum(int arr[], int n, int total)
{
    // Base case initialization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= total; j++)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }

    // Build DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= total; j++)
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
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    // Build the DP table once
    subsetSum(arr, n, total);

    int minDiff = INT_MAX;
    int s1 = 0, s2 = 0;

    // Check only till total/2
    for (int j = 0; j <= total / 2; j++)
    {
        if (t[n][j])
        {
            int diff = total - 2 * j;

            if (diff < minDiff)
            {
                minDiff = diff;
                s1 = j;
                s2 = total - j;
            }
        }
    }

    cout << "\nSubset Sum 1 = " << s1 << endl;
    cout << "Subset Sum 2 = " << s2 << endl;
    cout << "Minimum Difference = " << minDiff << endl;

    return 0;
}