class Solution {
public:
    void print(vector<int> &nums){
        for(int i=0;i<nums.size();i++){ 
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
    }
    void print(vector<vector<int>> &nums){
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){ 
                cout<<nums[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        print(nums);
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=n-1;i>=2;i--){
            int start = 0;
            int end = i-1;
            int target = nums[i] * -1;
            while(start<end){
                int sum = nums[start] + nums[end];
                if(sum<target){
                    start++;
                }
                else if(sum>target){
                    end--;
                }
                else{
                    res.push_back({nums[start],nums[end],nums[i]});
                    while(start<end && nums[start]==nums[start+1]){
                        start++;
                    }
                    start++;
                }
            }
            while(i>=2 && nums[i]==nums[i-1]){
                i--;
            }
        }
        return res;
    }
};