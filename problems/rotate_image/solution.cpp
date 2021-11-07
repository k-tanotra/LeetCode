class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        for(int i=0;i<n/2;i++){
            int s = i;
            int e = n-1-i;
            while(e>i){
                int a,b,c,d;
                a = m[i][s];
                b = m[s][n-1-i];
                c = m[n-1-i][e];
                d = m[e][i];
                m[i][s] = d;
                m[s][n-1-i] = a;
                m[n-1-i][e] = b;
                m[e][i] = c;
                
                s++;
                e--;
            }
        }
    }
};