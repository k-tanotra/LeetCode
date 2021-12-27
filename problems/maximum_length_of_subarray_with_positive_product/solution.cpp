class Solution {
public:
    int getMaxLen(vector<int>& nums) {
       int firstNeg = -1;
       int neg = 0;
       int ans = 0;
       int len = 0;
       int val = 0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]>0){
               len++;
           }
           else if(nums[i]<0){
               neg++;
               if(neg%2==0){
                   len = val + i-firstNeg-1 + 2;
               }
               else{
                   if(firstNeg==-1){
                       firstNeg = i;
                       val = len;
                       len = 0;
                   }
                   else{
                       len = i-firstNeg;
                   }
               }
           }
           else{
               neg = 0;
               firstNeg = -1;
               len = 0;
           }
           ans = max(ans,len);
       }
       
       return ans;
    }
};