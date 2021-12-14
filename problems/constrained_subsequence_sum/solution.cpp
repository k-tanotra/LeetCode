class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int temp;
        int max_neg = INT_MIN;
        priority_queue<pair<int,int>> pq;
        int c = 0;
       // pq.push({0,-1});
        for(int i=0;i<nums.size();i++){
            while(!pq.empty() && i-pq.top().second > k){
                ans = max(ans,pq.top().first);
                pq.pop();
            }
            if(pq.empty()){
                pq.push({max(nums[i],0),i});
            }
            else{
                pq.push({max(nums[i]+pq.top().first,0),i});
            }
            
            if(nums[i]<0){
                c++;
                max_neg = max(nums[i],max_neg);
            }
        }
        /*
        priority_queue<pair<int,int>> pr = pq;
        while(!pr.empty()){
            cout<<pr.top().first<<" "<<pr.top().second<<endl;
            pr.pop();
        }*/
        if(c==nums.size()){
            return max_neg;
        }
        
        if(!pq.empty()){
            ans = max(ans,pq.top().first);
        }
        return ans;
    }
};