class Solution {
public:
    bool check(int mid,vector<int> weights,int days){
        
        int sum = 0;
        int used = 0;
        for(int i=0;i<weights.size();i++){
            if(sum + weights[i]<=mid){
                sum += weights[i];
            }
            else{
                sum = 0;
                used++;
                sum += weights[i];
            }
            if(used>=days){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int mx = 0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            mx = max(mx,weights[i]);
        }
        int start = mx;
        int end = sum;
        while(start<end){
            int mid = start + (end-start)/2;
            if(check(mid,weights,days)){
                end = mid;
            }
            else{
                start = mid+1;
            }
        }
        
        return start;
    }
};