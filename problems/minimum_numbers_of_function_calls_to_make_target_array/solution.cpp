class Solution {
public:
    int minOperations(vector<int>& nums) {
        int two = -1;
        int calls = 0;
        for(int i=0;i<nums.size();i++){
            int cur = nums[i];
            int ones = 0;
            int curTwo = 0;
            while(cur!=0){
                if(cur%2==0){
                    cur=cur/2;
                    curTwo++;
                }
                else{
                    cur=cur-1;
                    ones++;
                }
            }
            calls += ones;
            two = max(two,curTwo);
        }
        calls += two;
        return calls;
    }
};