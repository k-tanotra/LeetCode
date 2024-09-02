class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int n:chalk){
            sum+=n;
        }
        int q = k/sum;
        int r = k%sum;
        for(int i=0;i<chalk.size();i++){
            if(r<chalk[i]){
                return i;
            }
            else{
                r-=chalk[i];
            }
        }
        return -1;
    }
};