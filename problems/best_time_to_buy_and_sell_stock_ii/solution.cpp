class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int start = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>start){
                profit += prices[i] - start;
                start = prices[i];
            }
            else{
                start = prices[i];
            }
        }
        return profit;
    }
};