class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single = 0;
        int db = 0;
        int sum = 0;
        for(int n:nums){
            if(n>=10 && n<=99){
                db += n;
            }
            else if(n>=0 && n<=9){
                single += n;
            }
            sum += n;
        }
        
        if(db > sum-db)
            return true;
        if(single > sum -single)
            return true;
        return false;
    }
};