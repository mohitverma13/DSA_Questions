class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=n-1;
        int id=0;
        int fill=1;
        while(top<=bottom && left<=right){
            if(id==0){
                for(int i=left;i<=right;i++){
                    matrix[top][i]=fill;
                    fill++;
                }
                top++;
                id++;
            }
            else if(id==1){
                for(int i=top;i<=bottom;i++){
                    matrix[i][right]=fill;
                    fill++;
                }
                right--;
                id++;
            }
            else if(id==2){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i]=fill;
                    fill++;
                }
                bottom--;
                id++;
            }
            else if(id==3){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left]=fill;
                    fill++;
                }
                left++;
                id++;
            }
            id=id%4;
        }
        return matrix;
    }
};