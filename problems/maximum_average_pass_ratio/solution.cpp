class Solution {
public:
    struct point{
        double diff;
        double nu;
        double den;
        int index;
    };
    static bool cmp(point& a,point& b){
        return a.diff<b.diff;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        vector<int> dp(n,0);
        
        priority_queue<point,vector<point>,function<bool(point&,point&)> > pq(cmp);
        double ans = 0.00000;
        for(int i=0;i<n;i++){
            point p;
            p.index = i;
            p.den = classes[i][1]+1;
            p.nu = classes[i][0]+1;
            p.diff = (classes[i][0]+1)/(1.00000* classes[i][1]+1) - classes[i][0]/(1.00000*classes[i][1]);
            pq.push(p);
        }
        
        int k = extraStudents;
        while(k>0){
            dp[pq.top().index]++;
            point x = pq.top();
            pq.pop();
            x.diff = (x.nu+1)/(1.00000* x.den+1) - x.nu/(1.00000*x.den);
            x.den = x.den + 1;
            x.nu = x.nu + 1;
            pq.push(x);
            k--;
        }
        
        for(int i=0;i<n;i++){
            ans += (classes[i][0]+dp[i])/(1.00000*classes[i][1]+dp[i]);
        }
        ans = ans/(1.00000*n);
        return ans;
    }
};