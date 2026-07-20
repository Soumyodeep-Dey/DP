#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int knapsack(int wt[], int val[], int W, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}

int main()
{
    int n, W;
    cout << "Enter the number of items and the maximum weight: ";
    cin >> n >> W;
    int wt[n], val[n];
    cout << "Enter the weights and values of the items: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    // Initialize the matrix t with 0 where i == 0 or j == 0
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0) 
            {
                t[i][j] = 0;
            }
        }
    }
    cout << knapsack(wt, val, W, n) << endl;

    // Wait for user input before exiting
    cout << "Press Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}