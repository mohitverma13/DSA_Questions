#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> solve(vector<pair<int,int>>&nums){
    int n=nums.size();
    vector<pair<int,int>>ans;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i].second==nums[j].first &&nums[j].second==nums[i].first ){
                ans.push_back({nums[j]});
            }
        }
    }
    return ans;
}
void print(vector<pair<int,int>> &result){
    for(auto p:result){
        cout<<"("<<p.first<<","<<p.second<<")"<<endl;
    }
}
int main(){
    vector<pair<int,int>>nums={{1,2},{5,4},{2,1},{6,7},{4,5}};
    cout<<"Return the pairs that are symmetric"<<endl;
    vector<pair<int,int>> result= solve(nums);
    print(result);
}