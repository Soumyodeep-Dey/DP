#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int knapsack(int wt[], int val[], int W, int n){
    if(n == 0 || W == 0) {
        return 0;
    }
    if(t[n][W] != -1) {
        return t[n][W];
    }
    if(wt[n-1] <= W) {
        return t[n][W] = max(val[n-1] + knapsack(wt, val, W - wt[n-1], n-1), knapsack(wt, val, W, n-1));
    } else {
        return t[n][W] = knapsack(wt, val, W, n-1);
    }
}

int main() {
    int n , W;
    cout << "Enter the number of items and the maximum weight: ";
    cin >> n >> W;
    int wt[n], val[n];
    cout << "Enter the weights and values of the items: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }
    memset(t, -1, sizeof(t));
    cout << knapsack(wt, val, W, n) << endl;
    cout << "Press Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}