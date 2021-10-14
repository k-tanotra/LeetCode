class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        
        v.push_back(0);
        v.push_back(1);
        
        if(n==1){
            return v;
        }
        int x = 1;
        int two = 2;
        while(x<n){
            for(int i=v.size()-1;i>=0;i--){
                v.push_back(v[i]+two);
            }
            two = two*2;
            x++;
        }
        
        return v;
    }
};