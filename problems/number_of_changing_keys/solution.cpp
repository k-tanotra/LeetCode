class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        for(int i=1;i<s.size();i++){
            if(abs(tolower(s[i])-tolower(s[i-1]))!=0)
                count++;
        }
        return count;
    }
};