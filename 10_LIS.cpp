#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int i, int prev, vector<int>& lis) {
    if (i == arr.size()) {
        return 0;
    }

    // Option 1: Exclude the current element
    vector<int> excLIS = lis; // To track the LIS for the exclude option
    int exc = solve(arr, i + 1, prev, excLIS);

    // Option 2: Include the current element if it is greater than the previous one
    int inc = 0;
    vector<int> incLIS = lis; // To track the LIS for the include option
    if (arr[i] > prev) {
        incLIS.push_back(arr[i]);
        inc = 1 + solve(arr, i + 1, arr[i], incLIS);
    }

    // Select the option with the maximum length and update the LIS
    if (inc > exc) {
        lis = incLIS;
        return inc;
    } else {
        lis = excLIS;
        return exc;
    }
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> lis; // To store the LIS sequence

    // Call the solve function
    int length = solve(arr, 0, INT_MIN, lis);

    // Print the LIS length and sequence
    cout << "Length of Longest Increasing Subsequence: " << length << endl;
    cout << "Longest Increasing Subsequence: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}