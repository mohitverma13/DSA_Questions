class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<Node*>>nodematrix(n,vector<Node*>(n));
        // vector<vector<Node*>>nodematrix(n,vector<Node*>(n,nullptr)); // Both work
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                nodematrix[i][j]=new Node(mat[i][j]);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i+1<n){
                    nodematrix[i][j]->down=nodematrix[i+1][j];
                }
                if(j+1<n){
                    nodematrix[i][j]->right=nodematrix[i][j+1];
                }
            }
        }
        return nodematrix[0][0];
    }
};