#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

// Recursive function for 0/1 Knapsack Problem
int solve(vector<Item>& itm, int w, int i) {
    // Base case: If we have processed all items or the knapsack capacity is 0
    if (i >= itm.size() || w <= 0) {
        return 0;
    }

    // Skip the current item
    int exclude = solve(itm, w, i + 1);

    // Include the current item if its weight is less than or equal to remaining capacity
    int include = 0;
    if (itm[i].weight <= w) {
        include = itm[i].value + solve(itm, w - itm[i].weight, i + 1);
    }

    // Return the maximum of including or excluding the current item
    return max(include, exclude);
}

int main() {
    int n, w;
    
    // Input number of items and knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> w;

    // Input items (value and weight)
    vector<Item> items(n);
    cout << "Enter the value and weight of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    // Call solve function and print result
    int maxValue = solve(items, w, 0);
    cout << "Maximum value that can be carried: " << maxValue << endl;

    return 0;
}
