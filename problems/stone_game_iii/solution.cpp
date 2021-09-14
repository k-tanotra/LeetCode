class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int len = stoneValue.size();
        vector<int> scores(len,0);
        vector<int> jumps(len,0);
        
        stoneValue.push_back(0);
        stoneValue.push_back(0);
        stoneValue.push_back(0);
        
        scores.push_back(0);
        scores.push_back(0);
        scores.push_back(0);
        jumps.push_back(0);
        jumps.push_back(0);
        jumps.push_back(0);
        
        int a,b,c;
        for(int i=len-1;i>=0;i--){
            a = stoneValue[i] + scores[i+1+jumps[i+1]];
            b = stoneValue[i] + stoneValue[i+1] + scores[i+2+jumps[i+2]];
            c = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] + scores[i+3+jumps[i+3]];
            
            scores[i] = max(max(a,b),c);
            if(a==scores[i]){
                jumps[i]  = 1;
            }
            else if(b==scores[i]){
                jumps[i] = 2;
            }
            else if(c==scores[i]){
                jumps[i] = 3;
            }
        }
        
        if(scores[0] > scores[jumps[0]]){
            return "Alice";
        }
        else if(scores[0] < scores[jumps[0]]){
            return "Bob";
        }
        return "Tie";
    }
};