class Solution {
public:
    struct point{
        int time;
        int weight;
        int index;
    };
    static bool free_cmp(point& b,point& a){
        if(a.weight<b.weight){
            return true;
        }
        else if(a.weight==b.weight){
            if(a.index<b.index){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
    static bool busy_cmp(point& b,point& a){
        return (a.time < b.time);
    }
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        priority_queue<point,vector<point>,function<bool(point&,point&)>> free(free_cmp);
        for(int i=0;i<servers.size();i++){
            point p;
            p.time = 0;
            p.weight = servers[i];
            p.index = i;
            free.push(p);
        }
        vector<int>  ans;
        priority_queue<point,vector<point>,function<bool(point&,point&)>> busy(busy_cmp);
        
        int i=0;
        int t=0;
        int n = tasks.size();
        while(i<n){
            t = max(t,i);
            while(!busy.empty() && busy.top().time<=t){
                point x  = busy.top();
                busy.pop();
                x.time = 0;
                free.push(x);
            }
            
            if(free.empty()){
                t = max(t,busy.top().time);
                continue;
            }
            
            point y = free.top();
            free.pop();
            y.time = tasks[i] + t;
            busy.push(y);
            ans.push_back(y.index);
            i++;
        }
        
        return ans;
    }
};