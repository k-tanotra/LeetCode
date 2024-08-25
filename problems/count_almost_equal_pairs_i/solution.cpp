class Solution {
public:
    vector<int> getFreq(int a){
        vector<int> freq(10,0);
        int digits = 0;
        while(a>0){
            freq[a%10]++;
            a = a/10;
            digits++;
        }
        freq[0] += 6-digits;
        return freq;
    }
    bool almost(int a,int b){
        vector<int> freq1 = getFreq(a);
        vector<int> freq2 = getFreq(b);
        
        if(freq1!=freq2){
            return false;
        }
        int diff = 0;
        for(int i=0;i<=6;i++){
            int x = 0;
            int y = 0;
            if(a>0){
                x = a%10;
                a = a/10;
            }
            if(b>0){
                y = b%10;
                b = b/10;
            }
            if(x!=y){
                diff++;
            }
        }
        if(diff==0 || diff==2){
            return true;
        }
        
        return false;
        
    }
    int countPairs(vector<int>& nums) {
        int cnt  = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(almost(nums[i],nums[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};