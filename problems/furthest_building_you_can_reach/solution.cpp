class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
       int len = heights.size();
       priority_queue<int,vector<int>,greater<int>> pq;
       
       for(int i=0;i<len-1;i++){
           int diff = heights[i+1] - heights[i];
           if(diff<=0)
               continue;
           
           pq.push(diff);
           if(pq.size()>ladders){
               int x = pq.top();
               pq.pop();
               if(x<=bricks){
                  bricks -= x;
               } else{
                  return i;
               } 
           }
       }
       return len-1;
    }
};