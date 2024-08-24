class Solution {
public:
    int rec(vector<int>& nums,int s,int e,int m){
        if(s>e){
            return 0;
        }
        if(m>3){
            return 0;
        }
        int diff;
        if(m==3){
            return nums[e] - nums[s];
        }
        return min(rec(nums,s,e-1,m+1),rec(nums,s+1,e,m+1));
    }
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4){
            return 0;
        }
        sort(nums.begin(),nums.end());
        return rec(nums,0,nums.size()-1,0);
    }
};