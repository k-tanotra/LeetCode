class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n);
        fact[0] = 0;
        if(n>=2)
            fact[1] = 1;
        for(int i=2;i<fact.size();i++){
            fact[i] = fact[i-1] * (i);
        }
        vector<int> numList = {1,2,3,4,5,6,7,8,9};
        int last = n-1;
        int curNum = 0;
        string ans = "";
        while(n>0){
            while(k>fact[last] && last!=0){
                k -= fact[last];
                curNum++;
            }
            ans += '0' + numList[curNum];
            numList.erase(numList.begin()+curNum);
            curNum=0;
            last--;
            n--;
        }
        return ans;
    }
};