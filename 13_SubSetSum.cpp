#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>& arr,int i,int sum){
    if(i >= arr.size()){
        return false;
    }

    if(sum == 0){
        return true;
    }

    bool ans1 = solve(arr,i+1,sum-arr[i]);
    bool ans2 = solve(arr,i+1,sum);

    return ans1 || ans2;
}

int main(){
    int sum = 9;
    vector<int> arr = {9, 13, 34, 14, 112, 15, 12};

    cout<<solve(arr,0,sum);
}