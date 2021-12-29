class Solution {
public:
    struct point{
        int c1;
        int c2;
        int c3;
    };
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<point> res(colors.size());
        vector<point> res2(colors.size());
        int n = colors.size();
        
        if(colors[0]==1)
            res[0] = {0,-1,-1};
        else if(colors[0]==2)
            res[0] = {-1,0,-1};
        else
            res[0] = {-1,-1,0};
        
        for(int i=1;i<colors.size();i++){
            res[i] = res[i-1];
            if(colors[i]==1){
                res[i].c1 = i;
            }
            else if(colors[i]==2){
                res[i].c2 = i;
            }
            else{
                res[i].c3 = i;
            }
        }
        /*
        for(int i=0;i<res.size();i++){
            cout<<res[i].c1<<" "<<res[i].c2<<" "<<res[i].c3<<endl;
        }
        */
        
        if(colors[n-1]==1)
            res2[n-1] = {n-1,-1,-1};
        else if(colors[n-1]==2)
            res2[n-1] = {-1,n-1,-1};
        else
            res2[n-1] = {-1,-1,n-1};
        
        for(int i=n-2;i>=0;i--){
            res2[i] = res2[i+1];
            if(colors[i]==1){
                res2[i].c1 = i;
            }
            else if(colors[i]==2){
                res2[i].c2 = i;
            }
            else{
                res2[i].c3 = i;
            }
        }
        /*
        cout<<endl;
        for(int i=0;i<res.size();i++){
            cout<<res2[i].c1<<" "<<res2[i].c2<<" "<<res2[i].c3<<endl;
        }
        */
        
        vector<int> ans;
        int a,b,c;
        for(int i=0;i<queries.size();i++){
            if(queries[i][1]==1){
                a = INT_MAX;
                b = INT_MAX;
                if(res[queries[i][0]].c1!=-1){
                    a = abs(res[queries[i][0]].c1 - queries[i][0]);
                }
                if(res2[queries[i][0]].c1!=-1){
                    b = abs(res2[queries[i][0]].c1 - queries[i][0]);
                }
                c = min(a,b);
                if(c==INT_MAX){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(c);
                }
            }
            else if(queries[i][1]==2){
                a = INT_MAX;
                b = INT_MAX;
                if(res[queries[i][0]].c2!=-1){
                    a = abs(res[queries[i][0]].c2 - queries[i][0]);
                }
                if(res2[queries[i][0]].c2!=-1){
                    b = abs(res2[queries[i][0]].c2 - queries[i][0]);
                }
                c = min(a,b);
                if(c==INT_MAX){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(c);
                }
            }
            else{
                a = INT_MAX;
                b = INT_MAX;
                if(res[queries[i][0]].c3!=-1){
                    a = abs(res[queries[i][0]].c3 - queries[i][0]);
                }
                if(res2[queries[i][0]].c3!=-1){
                    b = abs(res2[queries[i][0]].c3 - queries[i][0]);
                }
                c = min(a,b);
                if(c==INT_MAX){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(c);
                }
            }
        }
        return ans;
    }
};