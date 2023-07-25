class Solution {
public:
    void flipAtIndex(vector<int> &nums,int from,int to){
        while(from<to){
            swap(nums[from],nums[to]);
            from++;
            to--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        flipAtIndex(nums,0,nums.size()-1);
        flipAtIndex(nums,0,k-1);
        flipAtIndex(nums,k,nums.size()-1);
    }
};