class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
        long long sum = 0;
        int last = -1;
        for(int i=0;i<maximumHeight.size();i++){
            if(last==-1 || last>maximumHeight[i]){
                last = maximumHeight[i];
            }
            if(last<=0){
                return -1;
            }
            sum += last;
            last--;
        }
        return sum;
    }
};