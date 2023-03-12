class Solution {
public:
    int maxCoins(vector<int>& piles) {

        sort(piles.begin(),piles.end());

        int start = 0;
        int end = piles.size()-2;
        int sum = 0;
        
        while(start<end){
            sum += piles[end];
            start++;
            end=end-2;
        }

        return sum;
    }
};