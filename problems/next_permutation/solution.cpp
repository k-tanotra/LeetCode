class Solution {
public:
    int find(vector<int> nums,int s,int val){
        int diff = INT_MAX;
        int ans = -1;
        for(int i=s;i<nums.size();i++){
            if(nums[i]>val && nums[i]-val<=diff){
                diff = nums[i]-val;
                ans = i;
            }
        }
        return ans;
    }
    void nextPermutation(vector<int>& nums) {
       int pivot=0;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                pivot=i;
                //find closest number
                int k = find(nums,pivot,nums[i-1]);
                int temp = nums[k];
                nums[k] = nums[i-1];
                nums[i-1] = temp;
                break;
            }
        }
        sort(nums.begin()+pivot,nums.end());
    }
};