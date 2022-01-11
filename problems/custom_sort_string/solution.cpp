class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        
        string ans = "";
        for(int i=0;i<order.length();i++){
            if(m.find(order[i])!=m.end()){
                while(m[order[i]]>0){
                    ans+=order[i];
                    m[order[i]]--;
                }
            }
        }
        
        for(auto itr=m.begin();itr!=m.end();itr++){
            while(itr->second>0){
                ans+=itr->first;
                itr->second--;
            }
        }
        
        return ans;
    }
};