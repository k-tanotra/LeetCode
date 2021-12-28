class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        
        for(int i=0;i<n;i++){
            int leftSmall = 0;
            int leftGreater = 0;
            int rightSmall = 0;
            int rightGreater = 0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]){
                    leftSmall++;
                }
                else{
                    leftGreater++;
                }
            }
            for(int j=i+1;j<n;j++){
                if(rating[j]<rating[i]){
                    rightSmall++;
                }
                else{
                    rightGreater++;
                }
            }
            
            ans += (leftSmall*rightGreater) + (leftGreater*rightSmall);
        }
        
        return ans;
    }
};