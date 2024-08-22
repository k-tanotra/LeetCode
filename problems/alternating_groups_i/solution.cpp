class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(colors[i]==colors[i+2] && colors[i+1]!=colors[i]){
                cnt++;
            }
        }
        return cnt;
    }
};