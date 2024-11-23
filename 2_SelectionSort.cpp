#include<bits/stdc++.h>
using namespace std;

int PrntArray(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int SelectionSort(vector<int>& arr){
    int n = arr.size() + 1;
    for(int i=0;i<n-1;i++){
        int minIdx = i;
        for(int j=i;j<arr.size();j++){
            if(arr[i] > arr[j]){
                minIdx = j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};

    SelectionSort(arr);
    PrntArray(arr);

    return 0;
}