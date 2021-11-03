class Solution {
public:
    struct point{
        int idx;
        int ori;
        int val;
    };
    int largestRectangleArea(vector<int>& heights) {
        stack<point> s;
        point p;
        p.idx = 0;
        p.ori = 0;
        p.val = heights[p.idx];
        
        s.push(p);
        
        int len = heights.size();
        int ans = p.val;
        for(int i=1;i<len;i++){
            point x;
            if(s.top().val>heights[i]){
                while(!s.empty() && s.top().val>heights[i]){
                     ans = max(ans,s.top().val*(i-s.top().idx));
                     s.pop();
                }
                
                s.empty() ? x.idx = 0 : x.idx = s.top().ori+1;
                x.val = heights[i];
                x.ori = i;
                s.push(x);
            }
            else if(s.top().val<heights[i]){
                ans = max(ans,heights[i]);
                x.idx = i;
                x.val = heights[i];
                x.ori = i;
                s.push(x);
            }
            else{
                s.top().ori = i;
            }
        }
        
        while(!s.empty()){
            ans = max(ans,s.top().val*(len-s.top().idx));
            s.pop();
        }
        
        return ans;
    }
};