#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr){
    int currentSum=0;
    int multiplier=1;
    int totalSum=0;
    for(int i=arr.size()-1;i>=0;i--){
        currentSum = (arr[i] * multiplier )+ currentSum;
        totalSum+=currentSum;
        multiplier= multiplier * 10 + 1;
    }
    return totalSum;
}
int main(){
    vector<int>arr{1,2,3};
    int ans= solve(arr);
    cout<<ans;
}

// _____________arr=[1,2,3]___________
// _____________subarrays=[[1],[2],[3],[1,2],[1,2,3],[2,3]] _________treated as____________[ [1],[2],[3],[12],[123],[23] ]