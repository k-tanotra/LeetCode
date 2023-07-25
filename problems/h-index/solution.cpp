class Solution {
public:
    void print(vector<int> &nums){
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int ans = -1;
        vector<int> freq(1001,0);
        for(int i=0;i<n;i++){
            freq[citations[i]]++;
        }
        
        for(int i=freq.size()-1;i>=0;i--){
            if(i<freq.size()-1)
                freq[i] += freq[i+1];
           ans = max(ans,min(freq[i],i));
        }
        return ans;
    }
};
