class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int count = 1;
        int score = nums[0] + nums[1];
        for(int i=2;i<nums.size()-1;i++){
            if(nums[i]+nums[i+1] == score){
                //cout<<i<<endl;
                count++;
                i++;
            }
            else{
                break;
            }
        }
        return count;
    }
};