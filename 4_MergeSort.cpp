#include<bits/stdc++.h>
using namespace std;

void PrntArray(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Merge(vector<int>& arr,int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for(int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for(int i=0;i<n2;i++){
        R[i] = arr[mid + 1 + i];
    }

    int i=0,j = 0,k = 0;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[left + k] = L[i];
            i++;
        } else {
            arr[left + k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[left + k] = L[i];
        i++; k++;
    }

    while(j < n2){
        arr[left + k] = R[j];
        j++; k++;
    }
}

void MergeSort(vector<int>& arr,int left,int right) {
    if(left < right){
        int mid = left + (right - left) / 2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};

    MergeSort(arr,0,arr.size()-1);
    PrntArray(arr);

    return 0;
}