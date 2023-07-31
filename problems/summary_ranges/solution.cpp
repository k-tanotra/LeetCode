class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string start = "";
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            if(start.empty()){
                start = to_string(nums[i]);
            }
            if(i==nums.size()-1 || nums[i]+1!=nums[i+1]){
                if(stoi(start)==nums[i]){
                    ans.push_back(start);
                }
                else{
                    ans.push_back(start+"->"+to_string(nums[i]));
                }
                start = "";
            }
        }
        return ans;
    }
};