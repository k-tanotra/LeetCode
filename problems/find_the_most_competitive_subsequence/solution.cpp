class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        auto cmp = [](pair<int,int> a,pair<int,int> b){
            if(a.first>b.first){
                return true;
            }
            else if(a.first==b.first){
                if(a.second>b.second){
                    return true;
                }
            }
            return false;
        };
        priority_queue<pair<int,int> ,vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for(int i=0;i<=nums.size()-k;i++){
            pq.push({nums[i],i});
        }
        
        vector<int> ans;
        int lf = pq.top().second;
        int t = k;
        int next = nums.size()-k;
         
        /*
        while(!pq.empty()){
            cout<<pq.top().first<<" "<<pq.top().second<<endl;
            pq.pop();
        }*/
        
        
        while(t>0){
            while(!pq.empty() && pq.top().second<lf){
                pq.pop();
            }
            ans.push_back(pq.top().first);
            lf = pq.top().second;
           // if(!pq.empty())
            pq.pop();
            next++;
            if(next<nums.size())
                pq.push({nums[next],next});
            t--;
        }
        
        /*
        while(!pq.empty()){
            cout<<pq.top().first<<" "<<pq.top().second<<endl;
            pq.pop();
        }
        */
        
        return ans;
    }
};