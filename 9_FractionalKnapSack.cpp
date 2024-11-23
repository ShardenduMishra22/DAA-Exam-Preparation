#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

// Comparator function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& itm) { 
    // Sort items by value-to-weight ratio
    sort(itm.begin(), itm.end(), compare);

    double res = 0.0; // Initialize result

    for (int i = 0; i < itm.size(); i++) {
        if (itm[i].weight <= W) {
            // Take the full item
            W -= itm[i].weight;
            res += itm[i].value;
        } else {
            // Take the fraction of the item that fits
            res += itm[i].value * ((double)W / itm[i].weight);
            break; // Knapsack is full
        }
    }

    return res; // Return the maximum value
}

int main() {
    int n, W;

    // Input number of items and knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    // Input items (value and weight)
    vector<Item> items(n);
    cout << "Enter the value and weight of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    // Call fractionalKnapsack function and print result
    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in the knapsack: " << fixed << setprecision(2) << maxValue << endl;

    return 0;
}