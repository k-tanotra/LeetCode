class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> v(n,0);
        int mini = INT_MAX;
        for(int i=k;i>=0;i--){
            mini = min(nums[i],mini);
            v[i] = mini;
        }
        mini = INT_MAX;
        for(int i=k;i<n;i++){
            mini = min(nums[i],mini);
            v[i] = mini;
        }
        
        int i=0;
        int j=n-1;
        
        int ans = v[k];
        while(i<=k && j>=k){
            ans = max(ans,min(v[i],v[j])*(j-i+1));
            if(j==k || v[i]<=v[j]){
                i++;
            }
            else if(i==k || v[i]>v[j]){
                j--;
            }
        }
        
        return ans;
    }
};