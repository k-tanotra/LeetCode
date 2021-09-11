class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int len = queries.size();
        int len2 = nums.size();
        
        vector<int> sum;
        int ans = 0;
        for(int i=0;i<len2;i++){
            if(nums[i]%2==0){
                ans += nums[i];
            }
        }
        int a,b;
        for(int i=0;i<len;i++){
            a = nums[queries[i][1]];
            b = a + queries[i][0];
            if(a%2==0 && b%2==0){
                sum.push_back(ans-a+b);
                ans = ans-a+b;
            }
            else if(a%2==0 && b%2!=0){
                sum.push_back(ans-a);
                ans = ans-a;
            }
            else if(a%2!=0 && b%2==0){
                sum.push_back(ans+b);
                ans = ans+b;
            }
            else{
                sum.push_back(ans);
            }
            nums[queries[i][1]] = b;
        }
        
        return sum;
    }
};