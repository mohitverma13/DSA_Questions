class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int id=0;
        int top=0;
        int left=0;
        int bottom=m-1;
        int right=n-1;
        vector<int>ans;
        while(top<=bottom && left<=right){
            if(id==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                id++;
                top++;
            }
            else if(id==1){
                for(int i=top;i<=bottom;i++){
                    ans.push_back(matrix[i][right]);
                }
                id++;
                right--;
            }
            else if(id==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                id++;
                bottom--;
            }
            else if(id==3){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                id++;
                left++;
            }
            id=id%4;
        }
        return ans;
    }
};