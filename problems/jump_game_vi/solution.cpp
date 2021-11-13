class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int sum = 0;
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        for(int i=1;i<nums.size();i++){
            while(!pq.empty() && pq.top().second+k<i){
                pq.pop();
            }
            if(pq.empty()){
                pq.push({nums[i],i});
            }
            else{
                pq.push({nums[i]+pq.top().first,i});
            }
        }
        
        while(!pq.empty()){
            if(pq.top().second==nums.size()-1){
                sum = pq.top().first;
                break;
            }
            pq.pop();
        }
        return sum;
    }
};