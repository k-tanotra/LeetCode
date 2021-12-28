class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        int rotIdx = -1;
        if(start==0){
            rotIdx = 0;
        }
        else if(start==1){
            rotIdx = 1;
        }
        int beg = 2;
        while(beg<pow(2,n)){
            int x = res.size();
            for(int i=x-1;i>=0;i--){
                res.push_back(res[i]+beg);
                if(res[i]+beg==start){
                    rotIdx = res.size()-1;
                }
            }
            beg = beg*2;
        }
        
        rotate(res.begin(),res.begin()+rotIdx,res.end());
        return res;
        
    }
};