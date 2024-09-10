class Solution {
public:
    int gcd(int a,int b){
        while(b!=0){
            int rem=a%b;
            a=b;
            b=rem;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int>gcdArr;
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            int gcdAns=gcd(temp->val,temp->next->val);
            ListNode* n=new ListNode(gcdAns);
            n->next=temp->next;
            temp->next=n;
            temp=temp->next->next;
        }
        return head;
    }
};