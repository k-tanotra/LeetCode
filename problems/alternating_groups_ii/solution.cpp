class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int sz = 1;
        int i = 0;
        int cnt = 0;
        while(i<n){
            if(colors[i%n]!=colors[(i+1)%n]){
                int start = i;
                while(colors[i%n]!=colors[(i+1)%n] && sz<k){
                    i++;
                    sz++;
                }
                if(sz==k){
                    cnt++;
                    while(i-k+2<n && colors[i%n]!=colors[(i+1)%n]){
                        cnt++;
                        i++;
                    }
                }
            }
            else{
                i++;
            }
            sz = 1;
        }
        return cnt;
    }
};