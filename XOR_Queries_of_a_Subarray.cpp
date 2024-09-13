class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i=1;i<arr.size();i++){
            arr[i]=arr[i] ^ arr[i-1];
        } 
// [0,3]-->means XorSum from 0 to 3rd index => XorSum at index 3;
//[1,2]---> means XorSum form index 1 to 2 => XorSum of Index (1-0)^ XorSum at index 2 ---> to remove contribution of XorSum index till index 1;
        vector<int>ans;
        for(auto query:queries){
            if(query[0]>0){
                ans.push_back( arr[query[0]-1] ^ arr[query[1]]);
            }else{
                ans.push_back(arr[query[1]]);
            }
        }
    return ans ;
    }
};