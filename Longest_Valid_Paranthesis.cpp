class Solution {
  public:
    int maxLength(string& str) {
        int open=0;
        int close=0;
        int maxi=0;
        // if start with close bracket then close bracket>open bracket
        // L----->R
        for(auto & ch: str){
            if(ch=='(')open++;
            else close++;
            if(open==close){
                maxi=max(maxi,2*open);
            }
            else if(close>open){
                open=0;
                close=0; // )(())(
            }
        }
        open=close=0;
        // R--->L
        for(int i=str.size()-1;i>=0;i--){
            char ch=str[i];
            if(ch=='(')open++;
            else close++;
            if(open == close){
                maxi=max(maxi,2*open);
            }
            else if(open>close){
                open=0;
                close=0; // )(())(
            }
        }
        return maxi;
    }
};