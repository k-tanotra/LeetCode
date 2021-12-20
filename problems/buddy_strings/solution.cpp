class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        bool found = false;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
           if(m.find(s[i])==m.end()){
               m[s[i]] = 1;
           }
           else{
               m[s[i]]++;
           }
           if(m[s[i]]>=2){
               found=true;
           }
        }
        for(int i=0;i<s.length();i++){
           if(m.find(goal[i])==m.end()){
               m[goal[i]] = -1;
           }
           else{
               m[goal[i]]--;
           }
        }
        for(auto itr=m.begin();itr!=m.end();itr++){
            //cout<<itr->first<<" "<<itr->second<<endl;
            if(itr->second!=0){
                return false;
            }
        }
        int diff = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
                diff++;
                if(diff>2){
                    return false;
                }
            }
        }
        if(diff!=2 && !found){
            return false;
        }
        return true;
    }
};