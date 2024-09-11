class Solution {
public:
    int minBitFlips(int start, int goal) {
      int count=0;
      int temp=start^goal;

      for(int i=0;i<31;i++){ //counting set bits 
        if(temp & (1<<i)){
            count++;
        }
      }
    return count;
    }
};

// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//       int count=0;
//       int temp=start^goal;

//       while(temp>0){ //counting set bits 
//         int rem=temp%2;
//         if(rem==1)count++;
//         temp=temp/2;
//       }
//     return count;
//     }
// };