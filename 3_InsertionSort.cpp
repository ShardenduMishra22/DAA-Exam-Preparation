#include<bits/stdc++.h>
using namespace std;

void PrntArray(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void InsertionSort(vector<int>& arr) {
    for(int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};

    InsertionSort(arr);
    PrntArray(arr);

    return 0;
}
