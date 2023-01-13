class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<long> prefix(n,0);
        prefix[0] = nums[0];
        int res = n+1;

        for(int i=0;i<n;i++){

            if(i>0){
                prefix[i] += prefix[i-1] + nums[i];
            }
            if(prefix[i]>=k){
                res  = min(res,i+1);
            }

            //pop front part
            while( !dq.empty() && prefix[i]-prefix[dq.front()] >=k ){
                res = min(res,i-dq.front());
                dq.pop_front();
            }

            // pop back part
            while( !dq.empty() && prefix[i] <= prefix[dq.back()] ){
                dq.pop_back();
            }

            dq.push_back(i);
        }
        //cout<<res<<endl;
        return res<=n ? res : -1;
    }
};