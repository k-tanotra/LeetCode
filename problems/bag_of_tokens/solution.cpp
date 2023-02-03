class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int start = 0;
        int end = tokens.size()-1;
        int score = 0;
        while(start<=end){
            if(power>=tokens[start]){
                score++;
                power -= tokens[start];
                start++;
            }
            else if(score>=1 && start!=end){
                power += tokens[end];
                end--;
                score--;
            }
            else{
                break;
            }
        }
        return score;
    }
};