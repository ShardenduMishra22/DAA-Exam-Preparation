#include<bits/stdc++.h>
using namespace std;

void PrntArray(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j < right; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void QuickSort(vector<int>& arr, int left, int right) {
    if(left < right) {
        int prtn = Partition(arr, left, right);
        QuickSort(arr, left, prtn - 1);
        QuickSort(arr, prtn + 1, right);
    }
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};

    QuickSort(arr, 0, arr.size() - 1);
    PrntArray(arr);

    return 0;
}