class Solution {
  public:
        Node* head=NULL;
        Node* prev=NULL;
    Node* solve(Node* root){
        if(!root)return NULL;
        solve(root->left);
        if(prev==NULL){
            head=root;
        }
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        solve(root->right);
        return head;
    }
    Node* bToDLL(Node* root) {
        return solve(root);
    }
};