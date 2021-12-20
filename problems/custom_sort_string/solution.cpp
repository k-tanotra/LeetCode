class Solution {
public:
    string customSortString(string order, string s) {
       unordered_map<char,int> m;
       unordered_map<int,char> m2;
       int p = 26;
       for(int i=0;i<order.length();i++){
           m[order[i]] = p;
           m2[p] = order[i];
           p--;
       }
       priority_queue<int> pq;
       for(int i=0;i<s.length();i++){
           if(m.find(s[i])==m.end()){
               m[s[i]] = p;
               m2[p] = s[i];
               p--;
           }
           pq.push(m[s[i]]);
       }
        
       string ans="";
        while(!pq.empty()){
            ans += m2[pq.top()];
            pq.pop();
        }
        
        return ans;
    }
};