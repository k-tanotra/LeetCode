class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int prev = *(s.begin());
        int mxLen = 1;
        int count = 1;
        for(auto itr=s.begin();itr!=s.end();itr++){
            if(itr==s.begin()){
                continue;
            }
            if(prev+1==*itr){
                count++;
                mxLen = max(mxLen,count);
            }
            else{
                count = 1;
            }
            prev = *itr;
        }
        return mxLen;;
    }
};