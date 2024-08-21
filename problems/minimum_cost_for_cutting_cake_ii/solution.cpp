class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
         auto cmp = [](int a,int b){
            return a>b;
        };
        sort(h.begin(),h.end(),cmp);
        sort(v.begin(),v.end(),cmp);
        
        int x = 0;
        int y = 0;
        long long cost=0;
        int cut;
        int vc = 1;
        int hc = 1;
        while(x<h.size() || y<v.size()){
            if(x<h.size() && y<v.size()){
                if(h[x]>=v[y]){
                    cut = h[x];
                    hc++;
                    x++;
                    cost += cut*vc;
                }
                else{
                    cut = v[y];
                    vc++;
                    cost += cut*hc;
                    y++;
                }
            }
            else if(x<h.size()){
                 cut = h[x];
                 hc++;
                 x++;
                 cost += cut*vc;
            }
            else if(y<v.size()){
                cut = v[y];
                vc++;
                cost += cut*hc;
                y++;
            }
        }
        return cost;
    }
};