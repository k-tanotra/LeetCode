class Solution {
public:
    int sumDigits(int num){
        int sum = 0;
        while(num>0){
            sum += num%10;
            num = num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            m[sumDigits(nums[i])].push_back(nums[i]);
        }
        int maxSum = -1;
        for(auto itr=m.begin();itr!=m.end();itr++){
            sort(itr->second.begin(),itr->second.end());
            int n = itr->second.size();
            if(n>=2){
                maxSum = max(maxSum,itr->second[n-1]+itr->second[n-2]);
            }
        }
        return maxSum;
    }
};