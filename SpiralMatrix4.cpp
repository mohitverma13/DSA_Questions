/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>matrix(m,vector<int>(n,-1));
        int id=0;//0,1,2,3
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;

        while(top<=bottom && left<=right &&  head != nullptr) {
            if(id==0){
                for(int i=left;head!=NULL && i<=right;i++){
                    matrix[top][i]=head->val;
                    head=head->next;
                }
                top++;
                id++;
            }
            else if(id==1){
                for(int i=top;head!=NULL && i<=bottom;i++){
                    matrix[i][right]=head->val;
                    head=head->next;
                }
                right--;
                id++;
            }
            else if(id==2){
                for(int i=right;head!=NULL && i>=left;i--){
                    matrix[bottom][i]=head->val;
                    head=head->next;
                }
                bottom--;
                id++;
            }
            else if(id==3){
                for(int i=bottom; head!=NULL && i>=top;i--){
                    matrix[i][left]=head->val;
                    head=head->next;
                }
                left++;
                id++;
            }
            id=id%4;
        }
        return matrix;

    }
};