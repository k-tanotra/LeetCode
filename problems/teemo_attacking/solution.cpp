class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int low = timeSeries[0];
        int high = low + duration - 1;
        for(int i=1;i<timeSeries.size();i++){
            if(timeSeries[i]>=low && timeSeries[i]<=high){
                ans+= timeSeries[i] - timeSeries[i-1];
                low = timeSeries[i];
                high = low + duration - 1;
            }
            else{
                ans+= high-low+1;
                low = timeSeries[i];
                high = low + duration - 1;
            }
        }
       ans += high-low+1; 
       return ans;
    }
};