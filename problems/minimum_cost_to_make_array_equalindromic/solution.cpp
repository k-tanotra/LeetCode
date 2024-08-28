class Solution {
public:
    bool isPalindrome(int n){
        string s = to_string(n);
        int start = 0;
        int end = s.size()-1;
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int nextHigher(int n){
        while(!isPalindrome(n)){
            n++;
        }
        return n;
    }
    int nextLower(int n){
        while(!isPalindrome(n)){
            n--;
        }
        return n;
    }
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid1 = -1;
        int mid2 = -1;
        unordered_set<int> res;
        if(n%2==0){
            mid1 = nums[n/2];
            mid2 = nums[n/2-1];
            res.insert(nextHigher(mid1));
            res.insert(nextLower(mid1));
            res.insert(nextHigher(mid2));
            res.insert(nextLower(mid2));
        }
        else{
            mid1 = nums[n/2];
            res.insert(nextHigher(mid1));
            res.insert(nextLower(mid1));
        }
        long long mx = -1;
        for(auto itr=res.begin();itr!=res.end();itr++){
            long long cost = 0;
            for(int j=0;j<nums.size();j++){
                cost += abs(nums[j]-*itr);
            }
            if(mx==-1){
                mx = cost;
            }
            if(cost<mx){
                mx = cost;
            }
        }
        return mx;
        
    }
};