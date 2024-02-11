class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int> given;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>0){
                given.push_back(1);
            }
            else if(nums[i]-nums[i-1]<0){
                given.push_back(-1);
            }
            else if(nums[i]-nums[i-1]==0){
                given.push_back(0);
            }
        }
        int count = 0;
       // cout<<"HELLO"<<endl;
       // cout<<nums.size()<<endl;
       // cout<<given.size()<<endl;
       // cout<<pattern.size()<<endl;
       // cout<<"EE"<<endl;
        for(int i=0;i<given.size();i++){
            if(pattern[0]==given[i]){
                int idx =0;
                while(idx<pattern.size() && i+idx<given.size() && pattern[idx]==given[i+idx]){
                    idx++;
                }
                if(idx==pattern.size()){
               //     cout<<i<<endl;
                    count++;
                }
            }
        }
        return count;
    }
};