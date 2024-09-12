class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>mp(26,0);
        for(auto ch : allowed){
            mp[ch-'a']=1;
        }
        int count=0;
        for(auto word:words){
            bool consistent = true;
            for(int i=0;i<word.length();i++){
                if(mp[word[i] - 'a']==0){
                    consistent = false;
                    break;
                }
        }
        if(consistent){
        count++;
        }
     }
     return count;
    }
};