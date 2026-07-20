#include<bits/stdc++.h>
using namespace std;

int knapsack(int weights[], int values[], int n, int W) {
    if(n == 0 || W == 0) {
        return 0;
    }
    if(weights[n-1] > W) {
        return knapsack(weights, values, n-1, W);
    } else {
        return max(values[n-1] + knapsack(weights, values, n-1, W - weights[n-1]), knapsack(weights, values, n-1, W));
    }
}

int main() {
    cout << "Enter the number of items and the maximum weight: ";
    int n, W;
    cin >> n >> W;
    int weights[n], values[n];
    cout << "Enter the weights and values of the items: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    cout << knapsack(weights, values, n, W) << endl;
    return 0;
}