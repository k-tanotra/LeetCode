class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>freq(n*n+1,0);
        int a;
        int b;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                freq[grid[i][j]]++;
            }
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]==2){
                b = i;
            }
            else if(freq[i]==0){
                a = i;
            }
        }
        return {b,a};
    }
};