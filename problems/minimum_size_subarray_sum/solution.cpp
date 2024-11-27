class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int end = 0;
        int prev = -1;
        int sum = 0;
        int minLen = INT_MAX;
        while(end<nums.size()){
            if(prev!=end){
                sum += nums[end];
                prev = end;
            }
             //cout<<left<<" "<<end<<endl;
             //cout<<sum<<" "<<prev<<endl;
             //cout<<minLen<<endl;
             //cout<<"***"<<endl;
            if(sum<target){
                end++;
            }
            else{
                minLen= min(minLen,end-left+1);
                sum -= nums[left];
                left++;
            }
        }
        if(minLen == INT_MAX)
            return 0;
        return minLen;
    }
};