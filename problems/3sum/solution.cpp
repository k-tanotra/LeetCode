class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<vector<int> > ans;
        map<vector<int>,bool> m;
        for(int i=0;i<len;i++){
            int target = -1*nums[i];
            int start = 0;
            int end = len-1;
            while(start<end){
                if(start==i){
                    start++;
                    continue;
                }
                else if(end==i){
                    end--;
                    continue;
                }
                
                int val = nums[start] + nums[end];
                if(val<target){
                    start++;
                }
                else if(val>target){
                    end--;
                }
                else if(val==target){
                    vector<int> a = {-1*target,nums[start],nums[end]};
                    sort(a.begin(),a.end());
                    if(m.find(a)==m.end()){
                         m.insert({a,true});
                         ans.push_back(a);
                    }
                    if(start<end && nums[start]==nums[start+1]){
                        while(start<end  && nums[start]==nums[start+1]){
                            start++;
                        }
                    }
                    else{
                        start++;
                    }
                    if(start<end  && nums[end]==nums[end-1]){
                            while(start<end  && nums[end]==nums[end-1]){
                            end--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};