class Solution {
public:
    int maximumLength(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<long long,long long> m;
        int ones = 0;
        for(int n:nums){
            m[n]++;
            if(n==1){
                ones++;
            }
        }
        if(ones%2==0){
            ones-=1;
        }
        int mx = 1;
        for(int n:nums){
            if(n==1){
                continue;
            }
            long long cur = n;
            int sz = 0;
            while(m[cur]>=1){
                if(m[cur]==1){
                    sz+=1;
                    break;
                }
                else
                    sz+=2;
                m[cur] = -1;
                cur = cur * cur;
            }
            if(sz%2==0){
                sz-=1;
            }
            if(sz>=mx){
                mx=sz;
            }
        }
        if(ones>=mx){
            mx = ones;
        }
        return mx;
    }
};