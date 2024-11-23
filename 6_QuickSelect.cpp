#include <bits/stdc++.h>
using namespace std;

void PrntArray(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Partition(vector<int>& arr, int l, int r) {
    int pvt = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < pvt) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[r]); // Correct pivot placement
    return i + 1;            // Return the pivot index
}

int QS(vector<int>& arr, int l, int r, int k) {
    if (l <= r) { // Base condition should be `<=`, not `<`
        int pvt = Partition(arr, l, r);

        if (pvt == k) {
            return arr[pvt];
        } else if (pvt > k) {
            return QS(arr, l, pvt - 1, k);
        } else {
            return QS(arr, pvt + 1, r, k);
        }
    }
    return -1; // Return -1 if k is invalid
}

int main() {
    vector<int> arr = {15, 43, 32, 21, 11,45,23,12,56,32};
    int n = arr.size();
    int k = 2; // Find the 2nd smallest element (1-based)

    int kthSmallest = QS(arr, 0, n - 1, k - 1); // Convert k to 0-based
    cout << "The " << k << "rd smallest element is: " << kthSmallest << endl;

    return 0;
}