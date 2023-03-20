class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        int hp = pos;
        int lp = pos-1;
        int n = arr.size();
        vector<int> ans;
        deque<int> dq;
        if(pos<0){
            pos = -1;
        }
        while(k>0){
            if(hp<n && lp>=0){
                if(abs(arr[hp]-x)<abs(arr[lp]-x)){
                    dq.push_back(arr[hp]);
                    hp++;
                }
                else{
                    dq.push_front(arr[lp]);
                    lp--;
                }
            }
            else if(hp<n){
                dq.push_back(arr[hp]);
                hp++;
            }
            else if(lp>=0){
                dq.push_front(arr[lp]);
                lp--;
            }
            k--;
        }

        for(auto itr=dq.begin();itr!=dq.end();itr++){
            ans.push_back(*itr);
        }
        return ans;
    }
};