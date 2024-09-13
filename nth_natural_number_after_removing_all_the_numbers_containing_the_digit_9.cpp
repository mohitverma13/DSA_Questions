class Solution {
  public:
    long long findNth(long long n) {
        long long count=0;
        long long ans=0;
        long long placeValue=1;
        while(n){
            long long digit=n%9;
            ans=ans+(digit*placeValue);
            n=n/9;
            placeValue=placeValue*10;
        }
        return ans;
    }
};

// same approach for other digits