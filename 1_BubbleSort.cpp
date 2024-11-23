#include<bits/stdc++.h>
using namespace std;

void PrntArray(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void BubbleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j + 1] < arr[j]) {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};

    BubbleSort(arr);
    PrntArray(arr);

    return 0;
}
