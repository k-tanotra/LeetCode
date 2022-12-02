class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2 != 0)
            return {};
        vector<long long> res;
        for(int i=2;finalSum-i>=i+2;i+=2){
            res.push_back(i);
            finalSum -= i;
        }
        res.push_back(finalSum);
        return res;
    }
};